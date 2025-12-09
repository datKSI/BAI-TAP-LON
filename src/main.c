#include <stdio.h>
#include <stdlib.h>
#include "../include/common_math.h"
#include "../include/logic_weather.h"
#include "../include/logic_solver.h"
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

    double can_chung = tinhNepChung(dc);
    double can_giay  = tinhNepGiay(dg);
    int la_chung = (dc < 8) ? 1 : 2;
    int la_giay  = (dg < 5) ? 1 : 2;

    int bc = 0, bg = 0;
    double nd = n;

    if (strcmp(weather, "Wind") == 0)
        giaiWind(n, can_chung, can_giay, ld, la_chung, la_giay, &bc, &bg, &nd);
    else if (strcmp(weather, "Cloud") == 0)
        giaiCloud(n, can_chung, can_giay, ld, la_chung, la_giay, &bc, &bg, &nd);
    else if (strcmp(weather, "Rain") == 0)
        giaiRain(n, can_chung, can_giay, ld, la_chung, la_giay, &bc, &bg, &nd);
    else if (strcmp(weather, "Fog") == 0)
        giaiFog(n, can_chung, can_giay, ld, la_chung, la_giay, &bc, &bg, &nd);
    else {
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "-1 -1 %.0f", n); fclose(fo); }
        return 0;
    }

    FILE *fo = fopen("output.out", "w");
    if (fo) {
        fprintf(fo, "%d %d %.3f", bc, bg, nd);
        fclose(fo);
    }

    return 0;
}
