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
    // TODO 1: Tính toán chi phí nguyên liệu cho 1 cái bánh.
    // - Nếp cho bánh chưng (dc^2) và bánh giầy (dg^2 * PI / 3).
    // - Lá dong (1 hoặc 2 lá tùy kích thước).
    // - Lưu ý: Xử lý trường hợp kích thước = 0 để tránh chia cho 0.

    // TODO 2: Xác định giới hạn vòng lặp (Max số bánh có thể nấu).

    // Biến lưu kết quả tốt nhất (Best Solution)
    int best_bc = 0, best_bg = 0;
    
    // TODO 3: Viết 2 vòng lặp lồng nhau (for i, for j).
    // - Duyệt tất cả khả năng số bánh chưng (i) và bánh giầy (j).
    // - Kiểm tra điều kiện: Đủ nếp và đủ lá không?
    // - Nếu đủ, tính số nếp dư.

    // TODO 4: So sánh để tìm phương án tối ưu (Logic khó nhất).
    // - Ưu tiên 1: Số nếp dư phải ít nhất (Min).
    // - Ưu tiên 2 (Khi nếp dư bằng nhau): Xét theo Weather.
    //      + Wind: Chọn phương án có nhiều Bánh Chưng nhất.
    //      + Rain: Chọn phương án cân bằng nhất (abs(bc-bg) min).
    //      + Fog: Chọn tổng số bánh ít nhất.
    //      + Cloud: Chọn phương án có nhiều Bánh Giầy nhất.

    // TODO 5: Ghi kết quả tìm được (best_bc, best_bg, min_nd) vào file output.out.
    // Lưu ý định dạng in ra file phải chuẩn theo đề bài.
}