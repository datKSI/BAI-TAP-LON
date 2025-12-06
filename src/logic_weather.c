#include <string.h>
#include <stdio.h>
#include "../include/logic_weather.h"
#include "../include/common_math.h"

/*
 * NHIỆM VỤ: XỬ LÝ BIẾN ĐỔI DỮ LIỆU DỰA TRÊN THỜI TIẾT
 */

// 1. Xử lý Nắng (Sun)
// Logic: Tra bảng ma trận -> Cập nhật nếp/lá -> Đổi thời tiết.
void handleSun(int *n, int *ld, int dc, int dg, char *weather) {
    if (strcmp(weather, "Sun") != 0) return;

    // TODO 1: Khai báo mảng 2 chiều [5][6] chứa các giá trị X% (Xem đề bài).
    
    // TODO 2: Tính chỉ số hàng (ld % 5) và cột (dc % 6) để lấy X.
    
    // TODO 3: Cập nhật giá trị *n (tăng thêm X%) và *ld (giảm đi X).
    // Gợi ý: Sử dụng hàm myRound() để làm tròn nếp.

    // TODO 4: Kiểm tra (dc + dg) % 3 để đổi tên biến weather thành Rain/Wind/Cloud.
}

// 2. Xử lý Sương mù (Fog)
// Logic: Thay đổi kích thước bánh (nhân đôi hoặc chia đôi).
void handleFog(int *dc, int *dg, char *weather) {
    if (strcmp(weather, "Fog") != 0) return;

    // TODO: Gọi hàm isFibonacci() để kiểm tra dc và dg.
    // - Nếu cả 2 là Fib: Giảm 50% kích thước.
    // - Ngược lại: Tăng gấp đôi kích thước.
    // Nhớ cập nhật trực tiếp vào con trỏ *dc và *dg.
}

// 3. Kiểm tra Mây (Cloud) - Số bạn bè
// Logic: Kiểm tra xem n và ld có phải cặp số bạn bè không.
bool checkAmicable(int n, int ld, char *weather) {
    if (strcmp(weather, "Cloud") != 0) return false;

    // TODO: Gọi hàm sumProperDivisors() cho n và ld.
    // - Kiểm tra định nghĩa số bạn bè (Tổng ước số này bằng số kia).
    // - Trả về true nếu đúng, false nếu sai.
    return false; // [PLACEHOLDER]
}