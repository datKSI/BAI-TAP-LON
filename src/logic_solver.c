#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/logic_solver.h"
#include "../include/common_math.h"


/*
 * NHIỆM VỤ: CHẠY VÒNG LẶP VÉT CẠN ĐỂ TÌM SỐ BÁNH TỐI ƯU
 */

void solve(int n, int dc, int dg, int ld, char *weather, int *bc, int *bg, double *nd) {
    // Biến kết quả tốt nhất
    int best_bc = 0;
    int best_bg = 0;
    double min_nd = (double)n;
    int best_pairs = -1;          // dùng cho Rain: số cặp min(bc,bg) lớn nhất
    int best_compare_value = -1;  // dùng cho tie-break khác
    // 1. Tính toán chi phí nguyên liệu cho 1 cái bánh.
    // Công thức nếp Bánh Chưng: dc^2 * sqrt(dc)
    double rice_chung = (double)dc * dc * sqrt((double)dc);
    // Công thức nếp Bánh Giầy: (dg^2 * PI) / 3
    double rice_giay = ((double)dg * dg * PI) / 3.0;
    // Tránh chia cho 0
    // Số lá dong cần dùng
    int leaf_chung = (dc < 8) ? 1:2; 
    int leaf_giay = (dg < 5) ? 1:2;

    // 2. Xác định giới hạn vòng lặp
    int max_bc = (rice_chung > 0) ? (int)((double)n / rice_chung) + 1 : n;
    int max_bg = (rice_giay > 0) ? (int)((double)n / rice_giay) + 1 : n;
    if (max_bc > n) max_bc = n;
    if (max_bg > n) max_bg = n;
    // 3. Vòng lặp Vét cạn (Brute-force)
    for (int i = 0; i <= max_bc; i++) {
        for (int j = 0; j <= max_bg; j++) {
            double current_rice_used = (i * rice_chung) + (j * rice_giay);
            int current_leaf_used = (i * leaf_chung) + (j * leaf_giay);
            // Kiểm tra điều kiện đủ tài nguyên
            if (current_rice_used <= (double)n && current_leaf_used <= ld) {
                double current_nd = (double)n - current_rice_used;

                /*
                 * Ưu tiên theo thời tiết:
                 * - Wind  : tối thiểu nếp dư, tie -> bc nhiều hơn
                 * - Cloud : tối thiểu nếp dư, tie -> bg nhiều hơn
                 * - Rain  : ưu tiên số cặp min(bc,bg) lớn nhất, tie -> nếp dư ít hơn, tie -> |bc-bg| nhỏ hơn
                 * - Fog   : tối thiểu nếp dư, tie -> tổng bánh (bc+bg) ít hơn
                 * - Khác  : tối thiểu nếp dư
                 */

                if (strcmp(weather, "Rain") == 0) {
                    int current_pairs = (i < j) ? i : j;
                    if (current_pairs > best_pairs ||
                        (current_pairs == best_pairs && current_nd < min_nd - 0.001) ||
                        (current_pairs == best_pairs && fabs(current_nd - min_nd) < 0.001 &&
                         abs(i - j) < best_compare_value)) {
                        best_pairs = current_pairs;
                        min_nd = current_nd;
                        best_bc = i;
                        best_bg = j;
                        best_compare_value = abs(i - j);
                    }
                } else if (strcmp(weather, "Wind") == 0) {
                    if (current_nd < min_nd - 0.001 ||
                        (fabs(current_nd - min_nd) < 0.001 && i > best_bc)) {
                        min_nd = current_nd;
                        best_bc = i;
                        best_bg = j;
                    }
                } else if (strcmp(weather, "Cloud") == 0) {
                    if (current_nd < min_nd - 0.001 ||
                        (fabs(current_nd - min_nd) < 0.001 && j > best_bg)) {
                        min_nd = current_nd;
                        best_bc = i;
                        best_bg = j;
                    }
                } else if (strcmp(weather, "Fog") == 0) {
                    int current_total = i + j;
                    if (current_nd < min_nd - 0.001 ||
                        (fabs(current_nd - min_nd) < 0.001 &&
                         (best_compare_value == -1 || current_total < best_compare_value))) {
                        min_nd = current_nd;
                        best_bc = i;
                        best_bg = j;
                        best_compare_value = current_total;
                    }
                } else {
                    if (current_nd < min_nd - 0.001) {
                        min_nd = current_nd;
                        best_bc = i;
                        best_bg = j;
                    }
                }
            }
        }
    }

    // 4. Trả kết quả qua con trỏ
    if (bc) *bc = best_bc;
    if (bg) *bg = best_bg;
    if (nd) *nd = min_nd;
}
