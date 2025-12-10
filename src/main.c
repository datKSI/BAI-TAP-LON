#include <stdio.h>
#include <stdlib.h>
#include "../include/logic_weather.h"
#include "../include/logic_solver.h"

// Helper function to write output and exit, to clean up main()
void writeOutputAndExit(int v1, int v2, double v3) {
    FILE *fo = fopen("output.out", "w");
    if (fo) {
        // Use %.0lf if nd is meant to be an integer in output, or %g for generic float
        fprintf(fo, "%d %d %g", v1, v2, v3);
        fclose(fo);
    }
    exit(0);
}

int main() {
    int n = 0, dc = 0, dg = 0, ld = 0; // init to avoid garbage on bad input
    char weather[50];
    int bc = 0, bg = 0;
    double nd;

    FILE *fi = fopen("input.inp", "r");
    if (!fi) {
        writeOutputAndExit(-1, -1, 0); // Input file not found
    }

    // Read inputs
    if (fscanf(fi, "%d %d %d %d %49s", &n, &dc, &dg, &ld, weather) != 5) {
        fclose(fi);
        writeOutputAndExit(-1, -1, 0); // Invalid input format
    }
    fclose(fi);

    // Validate inputs (the spec limits: n in [1,2000], ld in [1,600], dc/dg non-negative and not both zero)
    if (n <= 0 || n > 2000 || ld <= 0 || ld > 600 || dc < 0 || dg < 0 || (dc == 0 && dg == 0)) {
        writeOutputAndExit(-1, -1, n);
    }

    // Process Logic
    handleSun(&n, &ld, dc, dg, weather);
    handleFog(&dc, &dg, weather);

    // Check amicable early exit
    if (checkAmicable(n, ld, weather)) {
        writeOutputAndExit(0, 0, n);
    }

    // Calculation
    // Final Solver Call
    solve(n, dc, dg, ld, weather, &bc, &bg, &nd);

    // Final Output
    writeOutputAndExit(bc, bg, nd);

    return 0;
}
