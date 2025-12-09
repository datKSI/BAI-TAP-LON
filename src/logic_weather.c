#include <string.h>
#include <stdio.h>
#include "../include/logic_weather.h"
#include "../include/common_math.h"
void handleSun(int *n, int *ld, int dc, int dg, char *weather) {
    if (strcmp(weather, "Sun") != 0) return;
    int sunTable[5][6] = {
        { 5,  7, 10, 12, 15, 20 },
        {20,  5,  7, 10, 12, 15 },
        {15, 20,  5,  7, 10, 12 },
        {12, 15, 20,  5,  7, 10 },
        {10, 12, 15, 20,  5,  7 }
    };
    int row = (*ld) % 5;
    int col = dc % 6;
    int X = sunTable[row][col];
    double inc = (*n) * (X / 100.0);
    *n = *n + myRound(inc);
    *ld = *ld - X;
    int m = (dc + dg) % 3;

    if (m == 0)
        strcpy(weather, "Rain");
    else if (m == 1)
        strcpy(weather, "Wind");
    else
        strcpy(weather, "Cloud");
}
void handleFog(int *dc, int *dg, char *weather) {
    if (strcmp(weather, "Fog") != 0) return;
    int isDcFib = isFibonacci(*dc);
    int isDgFib = isFibonacci(*dg);
    if (isDcFib && isDgFib) {
        *dc = *dc / 2;
        *dg = *dg / 2;
    } else {
        *dc = *dc * 2;
        *dg = *dg * 2;
    }
}
bool checkAmicable(int n, int ld, char *weather) {
    if (strcmp(weather, "Cloud") != 0)
        return false;
    int sumN  = sumProperDivisors(n);
    int sumLd = sumProperDivisors(ld);
    if (sumN == ld && sumLd == n)
        return true;
    return false;
}
