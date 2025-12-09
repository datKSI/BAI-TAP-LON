#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "../include/logic_solver.h"
#include "../include/common_math.h"

/*
 * NHIỆM VỤ: CHẠY VÒNG LẶP VÉT CẠN ĐỂ TÌM SỐ BÁNH TỐI ƯU
 */

void solve(int n, int dc, int dg, int ld, char *weather) {
    // 1. Tính toán chi phí nguyên liệu cho 1 cái bánh.
    // Công thức nếp Bánh Chưng: dc^2 * sqrt(dc)
    double rice_chung = (double)dc * dc * sqrt((double)dc);
    // Công thức nếp Bánh Giầy: (dg^2 * PI) / 3
    double rice_giay = ((double)dg * dg * PI) / 3.0;

    // Tránh chia cho 0
    if (dc == 0) rice_chung = 1e9;
    if (dg == 0) rice_giay = 1e9;

    // Số lá dong cần dùng
    int leaf_chung = (dc < 8) ? 1 : 2; 
    int leaf_giay = (dg < 5) ? 1 : 2;

    // 2. Xác định giới hạn vòng lặp
    int max_bc = (int)((double)n / rice_chung);
    int max_bg = (int)((double)n / rice_giay);
   
    // Biến lưu kết quả tốt nhất
    int best_bc = 0, best_bg = 0;
    double min_nd = (double)n; // Mặc định dư tất cả
    int found = 0;
    
    // 3. Vòng lặp Vét cạn (Brute-force)
    // SỬA LỖI: Dùng dấu chấm phẩy ; trong vòng for, không dùng :
    for (int i = 0; i <= max_bc; i++) {
        for (int j = 0; j <= max_bg; j++) {
            
            double used_rice = i * rice_chung + j * rice_giay;
            int used_leaf = i * leaf_chung + j * leaf_giay;

            // Kiểm tra điều kiện đủ tài nguyên
            if (used_rice <= n && used_leaf <= ld) {
                double current_nd = n - used_rice;
                int is_better = 0;

                if (!found) {
                    is_better = 1;
                } else {
                    // --- SO SÁNH TỐI ƯU ---
                    // Ưu tiên 1: Nếp dư ít nhất (Sai số 0.001)
                    if (current_nd < min_nd - 0.001) {
                        is_better = 1;
                    } 
                    // Ưu tiên 2: Nếu nếp dư xấp xỉ nhau, xét theo Weather
                    else if (fabs(current_nd - min_nd) < 0.001) {
                        if (strcmp(weather, "Wind") == 0) {
                            // Wind: Ưu tiên nhiều Bánh Chưng (i max)
                            if (i > best_bc) is_better = 1;
                        } 
                        else if (strcmp(weather, "Rain") == 0) {
                            // Rain: Ưu tiên cân bằng (abs(bc-bg) min)
                            if (abs(i - j) < abs(best_bc - best_bg)) is_better = 1;
                        } 
                        else if (strcmp(weather, "Fog") == 0) {
                            // Fog: Ưu tiên tổng số bánh ít nhất (i+j min)
                            if ((i + j) < (best_bc + best_bg)) is_better = 1;
                        } 
                        else if (strcmp(weather, "Cloud") == 0) {
                            // Cloud: Ưu tiên nhiều Bánh Giầy (j max)
                            if (j > best_bg) is_better = 1;
                        }
                    }
                }

                // Cập nhật kết quả nếu tìm thấy phương án tốt hơn
                if (is_better) {
                    best_bc = i;
                    best_bg = j;
                    min_nd = current_nd;
                    found = 1;
                }
            }
        }
    }

    // 4. Ghi kết quả
    FILE *fout = fopen("output.out", "w");
    if (fout) {
        if (found) 
            fprintf(fout, "%d %d %.3f", best_bc, best_bg, min_nd);
        else 
            fprintf(fout, "0 0 %.3f", (double)n); // Không nấu được gì
        fclose(fout);
    }
}
