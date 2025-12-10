#include <string.h>
#include <stdio.h>
#include <math.h>
#include "../include/logic_weather.h"
#include "../include/common_math.h"

/*
 * NHIỆM VỤ: XỬ LÝ BIẾN ĐỔI DỮ LIỆU DỰA TRÊN THỜI TIẾT
 */

/* ===========================================================
 * 1. Xử lý Nắng (Sun)
 * Logic: Tra bảng X -> Cập nhật nếp và lá dong -> Đổi thời tiết.
 * ===========================================================*/
void handleSun(int *n, int *ld, int dc, int dg, char *weather) {
    if (strcmp(weather, "Sun") != 0) return;

    // TODO 1: Khai báo mảng 2 chiều [5][6] chứa các giá trị X% (theo bảng đề bài)
    int sunTable[5][6] = {
        { 5,  7, 10, 12, 15, 20 },
        {20,  5,  7, 10, 12, 15 },
        {15, 20,  5,  7, 10, 12 },
        {12, 15, 20,  5,  7, 10 },
        {10, 12, 15, 20,  5,  7 }
    };

    // TODO 2: Tính chỉ số hàng (ld % 5) và cột (dc % 6)
    int row = (*ld) % 5;
    int col = dc % 6;
    int X = sunTable[row][col];

    // TODO 3: Cập nhật *n (tăng thêm X%) và *ld (giảm đi X)
    double inc = (*n) * (X / 100.0);
    // Đề yêu cầu làm tròn X% thành số nguyên, tham chiếu output cho thấy dùng floor
    int inc_int = (int)floor(inc + 1e-9);
    *n = *n + inc_int;
    *ld = *ld - X;

    // TODO 4: Đổi thời tiết theo (dc + dg) % 3
    int m = (dc + dg) % 3;

    if (m == 0)
        strcpy(weather, "Rain");
    else if (m == 1)
        strcpy(weather, "Wind");
    else
        strcpy(weather, "Cloud");
}


/* ===========================================================
 * 2. Xử lý Sương mù (Fog)
 * Logic: Kiểm tra dc và dg có phải số Fibonacci
 *         - Nếu cả 2 thuộc Fibonacci => giảm 50%
 *         - Ngược lại => tăng gấp đôi
 * ===========================================================*/
void handleFog(int *dc, int *dg, char *weather) {
    if (strcmp(weather, "Fog") != 0) return;

    int isDcFib = isFibonacci(*dc);
    int isDgFib = isFibonacci(*dg);

    if (isDcFib && isDgFib) {
        // Cả 2 đều là số Fibonacci → chia đôi (giảm 50%)
        *dc = *dc / 2;
        *dg = *dg / 2;
    } else {
        // Một hoặc cả hai không phải → tăng gấp đôi
        *dc = *dc * 2;
        *dg = *dg * 2;
    }
}


/* ===========================================================
 * 3. Mây (Cloud) – Kiểm tra số bạn bè
 * Logic: n và ld là số bạn bè nếu:
 *        sumProperDivisors(n) == ld  AND
 *        sumProperDivisors(ld) == n
 * ===========================================================*/
bool checkAmicable(int n, int ld, char *weather) {
    if (strcmp(weather, "Cloud") != 0)
        return false;

    int sumN  = sumProperDivisors(n);
    int sumLd = sumProperDivisors(ld);

    if (sumN == ld && sumLd == n)
        return true;

    return false;
}
