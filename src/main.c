#include <stdio.h>
#include <stdlib.h>
#include "../include/common_math.h"
#include "../include/logic_weather.h"
#include "../include/logic_solver.h"

/*
 * NHIỆM VỤ: QUẢN LÝ LUỒNG CHƯƠNG TRÌNH (MAIN FLOW)
 */

int main() {
    // Khai báo biến
    int n, dc, dg, ld;
    char weather[50];

    // TODO 1: Mở file "input.inp" để đọc dữ liệu.
    // - Nếu mở lỗi hoặc file sai định dạng -> Xử lý lỗi (in ra -1 -1 n).
    // - Đóng file sau khi đọc xong.

    // TODO 2: Gọi các hàm xử lý dữ liệu đầu vào (Data Processing).
    // - Gọi handleSun(...)
    // - Gọi handleFog(...)

    // TODO 3: Kiểm tra điều kiện dừng sớm (Early Exit).
    // - Gọi checkAmicable(...).
    // - Nếu là số bạn bè -> In ra "0 0 n" vào output.out và kết thúc chương trình (return 0).

    // TODO 4: Gọi hàm giải thuật toán (Solver).
    // - Gọi solve(...) để tính toán và ghi kết quả cuối cùng.

    return 0;
}