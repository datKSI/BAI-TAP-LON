#include "../include/logic_weather.h"
#include "../include/logic_solver.h"

double tinhNepChung(int dc) { return 1.0; }
double tinhNepGiay(int dg) { return 1.0; }
double tinhNepChung(int dc) { return 0; }
double tinhNepGiay(int dg) { return 0; }
void solve(int n, int dc, int dg, int ld, char *weather, int *bc, int *bg, double *nd) {
*bc = 0; *bg = 0; *nd = n;
}
@@ -18,47 +18,21 @@ int main() {
FILE *fi = fopen("input.inp", "r");
if (!fi) {
FILE *fo = fopen("output.out", "w");
        if (fo) {
            fprintf(fo, "-1 -1 0");
            fclose(fo);
        }
        if (fo) { fprintf(fo, "-1 -1 0"); fclose(fo); }
return 0;
}

if (fscanf(fi, "%d %d %d %d %49s", &n, &dc, &dg, &ld, weather) != 5) {
fclose(fi);
FILE *fo = fopen("output.out", "w");
        if (fo) {
            fprintf(fo, "-1 -1 %d", n);
            fclose(fo);
        }
        if (fo) { fprintf(fo, "-1 -1 %d", n); fclose(fo); }
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
    int amicable = checkAmicable(n, ld, weather);

int bc = 0, bg = 0;
double nd = n;
