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
    // Khai báo 
    int best_bc =0;             
    int best_bg =0;             
    double min_nd = (double)n;   
    int best_compare_value =-1;
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
  int max_bc = (rice_chung > 0) ? (int)((double)n / rice_chung)+ 1:n;
    int max_bg = (rice_giay > 0) ? (int)((double)n / rice_giay)+1:n;
    if (max_bc > n) max_bc =n;
    if (max_bg > n) max_bg =n;
    // 3. Vòng lặp Vét cạn (Brute-force)
    for (int i=0;i <= max_bc;i++) {
    for (int j=0;j <= max_bg;j++) {
        double current_rice_used =( i * rice_chung) +( j * rice_giay); 
         int current_leaf_used = (i * leaf_chung )+( j * leaf_giay); 
         // Khai báo biến so sánh
        int current_compare_value;
        bool is_better =false; 

            // Kiểm tra điều kiện đủ tài nguyên
    if (current_rice_used <= (double)n && current_leaf_used <= ld){
    double current_nd = (double)n - current_rice_used; 
                
                // --- SO SÁNH TỐI ƯU ---
                // Ưu tiên 1: Nếp dư ít nhất (Dùng 0.001)
        if (current_nd< min_nd -0.001){
        min_nd = current_nd;
        best_bc =i;
        best_bg =j;
        // Cập nhật giá trị Ưu tiên 2 (Lần đầu tiên)
         if (strcmp(weather,"Wind") == 0) best_compare_value =i;
         else if (strcmp(weather,"Cloud") == 0) best_compare_value =j;
         else best_compare_value = n*2; 
                } 
                // Ưu tiên 2: Nếu nếp dư xấp xỉ nhau, xét theo Weather
                else if (fabs(current_nd - min_nd) < 0.001){
                    // Wind: Ưu tiên nhiều Bánh Chưng (i max)
                    if (strcmp(weather, "Wind") == 0){ 
                        current_compare_value = i;
                        if (current_compare_value >best_compare_value) is_better =true;
                    } 
                    // Rain: Ưu tiên cân bằng (abs(bc-bg) min)
                    else if (strcmp(weather, "Rain") ==0){
                        current_compare_value = abs(i-j);
                        if (current_compare_value < best_compare_value) is_better = true;
                    } 
                    // Fog: Ưu tiên tổng số bánh ít nhất (i+j min)
                    else if (strcmp(weather, "Fog") == 0) {
                        current_compare_value = i+j;
                        if (current_compare_value <best_compare_value) is_better =true;
                    } 
                    // Cloud: Ưu tiên nhiều Bánh Giầy (j max)
                    else if (strcmp(weather, "Cloud") == 0){
                        current_compare_value = j;
                        if (current_compare_value > best_compare_value) is_better =true;
                    }
                    // Kết quả tốt nhất
                    if (is_better) {
                        best_bc = i;
                        best_bg = j;
                        best_compare_value = current_compare_value;
                    }
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
            fprintf(fout, "0 0 %.3f", (double)n);// Không nấu được gì
        fclose(fout);
    }
}
