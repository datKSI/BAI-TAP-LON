#include <stdio.h>
#include <stdlib.h>
#include "../include/common_math.h"
#include "../include/logic_weather.h"
#include "../include/logic_solver.h"
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

int validWeather(const char *w) {
    if (!w) return 0;
    return strcmp(w, "Sun") == 0 ||
           strcmp(w, "Fog") == 0 ||
           strcmp(w, "Rain") == 0 ||
           strcmp(w, "Wind") == 0 ||
           strcmp(w, "Cloud") == 0;
}

static int is_fib(int x) {
    if (x <= 0) return 0;
    int a = 1, b = 1;
    if (x == 1) return 1;
    while (b < x) {
        int t = a + b;
        a = b; b = t;
    }
    return b == x;
}

static int sum_proper_divisors(int x) {
    if (x <= 1) return 0;
    int s = 1;
    int r = (int) sqrt((double)x);
    for (int d = 2; d <= r; ++d) {
        if (x % d == 0) {
            s += d;
            int o = x / d;
            if (o != d) s += o;
        }
    }
    return s;
}

int laBanBe(int a, int b) {
    if (a <= 0 || b <= 0) return 0;
    return sum_proper_divisors(a) == b && sum_proper_divisors(b) == a;
}

double tinhNepChung(int dc) {
    if (dc <= 0) return 0.0;
    return (double)dc * dc * sqrt((double)dc);
}

double tinhNepGiay(int dg) {
    if (dg <= 0) return 0.0;
    return (double)dg * dg * PI / 3.0;
}

void xuLySun(double *n, int *ld, int dc, int dg, char *weather) {
    int G = ((dc % 6) + 6) % 6;
    int H = (((*ld) % 5) + 5) % 5;
    int tbl[5][6] = {
        {5,7,10,12,15,20},
        {20,5,7,10,12,15},
        {15,20,5,7,10,12},
        {12,15,20,5,7,10},
        {10,12,15,20,5,7}
    };
    int X = tbl[H][G];
    double add = (*n) * X / 100.0;
    long add_int = (long) floor(add + 0.5);
    *n += add_int;
    *ld -= X;
    if (*ld < 0) *ld = 0;
    int m = ((dc + dg) % 3 + 3) % 3;
    if (m == 0) strcpy(weather, "Rain");
    else if (m == 1) strcpy(weather, "Wind");
    else strcpy(weather, "Cloud");
}

void xuLyFog(int *dc, int *dg) {
    if (is_fib(*dc) && is_fib(*dg)) {
        *dc = (*dc) / 2; if (*dc < 1) *dc = 1;
        *dg = (*dg) / 2; if (*dg < 1) *dg = 1;
    } else {
        *dc = (*dc) * 2;
        *dg = (*dg) * 2;
    }
}

static void solve_priority(double n, double need_chung, double need_giay, int leaf, int leaf_chung, int leaf_giay, int priority, int *out_bc, int *out_bg, double *out_nd) {
    int bc = 0, bg = 0;
    int leaves = leaf;
    double remain = n;
    if (priority == 0) {
        if (need_chung > 0.0) {
            int by_n = (int)floor(remain / need_chung);
            int by_l = (leaf_chung > 0) ? leaves / leaf_chung : 0;
            bc = by_n < by_l ? by_n : by_l;
            remain -= bc * need_chung;
            leaves -= bc * leaf_chung;
        }
        if (need_giay > 0.0) {
            int by_n = (int)floor(remain / need_giay);
            int by_l = (leaf_giay > 0) ? leaves / leaf_giay : 0;
            bg = by_n < by_l ? by_n : by_l;
            remain -= bg * need_giay;
            leaves -= bg * leaf_giay;
        }
    } else {
        if (need_giay > 0.0) {
            int by_n = (int)floor(remain / need_giay);
            int by_l = (leaf_giay > 0) ? leaves / leaf_giay : 0;
            bg = by_n < by_l ? by_n : by_l;
            remain -= bg * need_giay;
            leaves -= bg * leaf_giay;
        }
        if (need_chung > 0.0) {
            int by_n = (int)floor(remain / need_chung);
            int by_l = (leaf_chung > 0) ? leaves / leaf_chung : 0;
            bc = by_n < by_l ? by_n : by_l;
            remain -= bc * need_chung;
            leaves -= bc * leaf_chung;
        }
    }
    *out_bc = bc; *out_bg = bg; *out_nd = remain;
}

static void solve_rain(double n, double need_chung, double need_giay, int leaf, int leaf_chung, int leaf_giay, int *out_bc, int *out_bg, double *out_nd) {
    int best_bc = 0, best_bg = 0;
    double best_left = n;
    int best_diff = 1<<30;
    int max_bc = 0;
    if (need_chung > 0.0) max_bc = (int)floor(n / need_chung);
    if (leaf_chung > 0) {
        int byleaf = leaf / leaf_chung;
        if (byleaf < max_bc || max_bc == 0) max_bc = byleaf;
    }
    if (max_bc < 0) max_bc = 0;
    for (int bc = 0; bc <= max_bc; ++bc) {
        double rem_n = n - bc * need_chung;
        int rem_leaf = leaf - bc * leaf_chung;
        if (rem_n < -1e-12 || rem_leaf < 0) break;
        int bg = 0;
        if (need_giay > 0.0 && rem_n >= need_giay && rem_leaf >= leaf_giay) {
            int by_n = (int)floor(rem_n / need_giay);
            int by_l = rem_leaf / leaf_giay;
            bg = by_n < by_l ? by_n : by_l;
        }
        double left = rem_n - bg * need_giay;
        if (left < 0) left = 0;
        int diff = abs(bc - bg);
        if (left + 1e-12 < best_left || (fabs(left - best_left) < 1e-12 && diff < best_diff)) {
            best_left = left;
            best_bc = bc;
            best_bg = bg;
            best_diff = diff;
        }
    }
    *out_bc = best_bc; *out_bg = best_bg; *out_nd = best_left;
}

static void solve_fog(double n, double need_chung, double need_giay, int leaf, int leaf_chung, int leaf_giay, int *out_bc, int *out_bg, double *out_nd) {
    int best_bc = 0, best_bg = 0;
    double best_left = n;
    int upper = leaf;
    if (upper <= 0) upper = 0;
    for (int t = 1; t <= upper; ++t) {
        double best_left_t = 1e100;
        int pick_bc = -1, pick_bg = -1;
        for (int bc = 0; bc <= t; ++bc) {
            int bg = t - bc;
            int need_leaf = bc * leaf_chung + bg * leaf_giay;
            if (need_leaf > leaf) continue;
            double used = bc * need_chung + bg * need_giay;
            if (used - n > 1e-12) continue;
            double left = n - used;
            if (left + 1e-12 < best_left_t) {
                best_left_t = left;
                pick_bc = bc; pick_bg = bg;
            }
        }
        if (pick_bc != -1) {
            best_bc = pick_bc; best_bg = pick_bg; best_left = best_left_t;
            break;
        }
    }
    *out_bc = best_bc; *out_bg = best_bg; *out_nd = best_left;
}

int main() {
    double n;
    int dc, dg, ld;
    char weather[50];

    FILE *fi = fopen("input.inp", "r");
    if (!fi) {
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "-1 -1 0"); fclose(fo); }
        return 0;
    }

    if (fscanf(fi, "%lf %d %d %d %49s", &n, &dc, &dg, &ld, weather) != 5) {
        fclose(fi);
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "-1 -1 %.0f", n); fclose(fo); }
        return 0;
    }
    fclose(fi);

    if (n <= 0 || ld <= 0 || (dc == 0 && dg == 0) || !validWeather(weather)) {
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "-1 -1 %.0f", n); fclose(fo); }
        return 0;
    }

    if (strcmp(weather, "Sun") == 0)
        xuLySun(&n, &ld, dc, dg, weather);

    if (strcmp(weather, "Fog") == 0)
        xuLyFog(&dc, &dg);

    if (strcmp(weather, "Cloud") == 0 && laBanBe((int)round(n), ld)) {
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "0 0 %.3f", n); fclose(fo); }
        return 0;
    }

    double need_chung = tinhNepChung(dc);
    double need_giay  = tinhNepGiay(dg);
    int leaf_chung = (dc < 8) ? 1 : 2;
    int leaf_giay  = (dg < 5) ? 1 : 2;

    int bc = 0, bg = 0;
    double nd = n;

    if (strcmp(weather, "Wind") == 0)
        solve_priority(n, need_chung, need_giay, ld, leaf_chung, leaf_giay, 0, &bc, &bg, &nd);
    else if (strcmp(weather, "Cloud") == 0)
        solve_priority(n, need_chung, need_giay, ld, leaf_chung, leaf_giay, 1, &bc, &bg, &nd);
    else if (strcmp(weather, "Rain") == 0)
        solve_rain(n, need_chung, need_giay, ld, leaf_chung, leaf_giay, &bc, &bg, &nd);
    else if (strcmp(weather, "Fog") == 0)
        solve_fog(n, need_chung, need_giay, ld, leaf_chung, leaf_giay, &bc, &bg, &nd);

    FILE *fo = fopen("output.out", "w");
    if (fo) {
        fprintf(fo, "%d %d %.3f", bc, bg, nd);
        fclose(fo);
    }

    return 0;
}
