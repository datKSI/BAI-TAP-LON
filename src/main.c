#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/common_math.h"
#include "../include/logic_weather.h"
#include "../include/logic_solver.h"

double tinhNepChung(int dc) { return 1.0; }
double tinhNepGiay(int dg) { return 1.0; }
void solve(int n, int dc, int dg, int ld, char *weather, int *bc, int *bg, double *nd) {
    *bc = 0; *bg = 0; *nd = n;
}

int main() {
    int n, dc, dg, ld;
    char weather[50];

    FILE *fi = fopen("input.inp", "r");
    if (!fi) {
        FILE *fo = fopen("output.out", "w");
        if (fo) {
            fprintf(fo, "-1 -1 0");
            fclose(fo);
        }
        return 0;
    }

    if (fscanf(fi, "%d %d %d %d %49s", &n, &dc, &dg, &ld, weather) != 5) {
        fclose(fi);
        FILE *fo = fopen("output.out", "w");
        if (fo) {
            fprintf(fo, "-1 -1 %d", n);
            fclose(fo);
        }
        return 0;
    }
    fclose(fi);

    if (n <= 0 || ld <= 0 || (dc == 0 && dg == 0)) {
        FILE *fo = fopen("output.out", "w");
        if (fo) {
            fprintf(fo, "-1 -1 %d", n);
            fclose(fo);
        }
        return 0;
    }

    handleSun(&n, &ld, dc, dg, weather);
    handleFog(&dc, &dg, weather);

    if (checkAmicable(n, ld, weather)) {
        FILE *fo = fopen("output.out", "w");
        if (fo) {
            fprintf(fo, "0 0 %d", n);
            fclose(fo);
        }
        return 0;
    }

    double nepc = tinhNepChung(dc);
    double nepg = tinhNepGiay(dg);

    int bc = 0, bg = 0;
    double nd = n;

    solve(n, dc, dg, ld, weather, &bc, &bg, &nd);

    FILE *fo = fopen("output.out", "w");
    if (fo) {
        fprintf(fo, "%d %d %.3f", bc, bg, nd);
        fclose(fo);
    }

    return 0;
}
