/* * ======================================================================================
 * DỰ ÁN: BÀI TẬP LỚN - TRUYỀN THUYẾT BÁNH CHƯNG BÁNH GIẦY (VER 4.0)
 * PHÂN CÔNG NHIỆM VỤ NHÓM 5 NGƯỜI - MÔ HÌNH GHÉP MODULE
 * ======================================================================================
 * * ⚠️ QUY TẮC SỐNG CÒN:
 * 1. Đây là "Code Khung Sườn" (Skeleton) để đảm bảo chạy đúng logic.
 * 2. Sau khi ghép code chạy thành công, MỖI NGƯỜI PHẢI TỰ GÕ LẠI (Re-type) phần của mình.
 * 3. Tuyệt đối KHÔNG copy-paste y nguyên file này nộp cho thầy (dính Đạo văn 0 điểm).
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* ======================================================================================
 * 👤 VỊ TRÍ 2: DEV TOÁN HỌC (Tiện ích dùng chung)
 * Nhiệm vụ: Viết các hàm toán học bổ trợ cho các bạn khác gọi.
 * ====================================================================================== */

// Hàm 1: Kiểm tra số Fibonacci (Dùng cho Fog)
// Output: true nếu n là số Fib, false nếu không.
bool isFibonacci(int n) {
    // [PHẦN CỦA BẠN: VIẾT CODE VÀO ĐÂY]
    return false; // placeholder
}

// Hàm 2: Tính tổng ước số thực sự (Dùng cho Cloud - Số bạn bè)
// Output: Tổng các ước của n (không bao gồm chính n).
int sumProperDivisors(int n) {
    // [PHẦN CỦA BẠN: VIẾT CODE VÀO ĐÂY]
    return 0; // placeholder
}

// Hàm 3: Làm tròn số thực thành số nguyên (Dùng cho Sun - tính X%)
// Output: Số nguyên đã làm tròn (VD: 3.6 -> 4).
int myRound(double n) {
    // [PHẦN CỦA BẠN: VIẾT CODE VÀO ĐÂY]
    return (int)round(n);
}

/* ======================================================================================
 * 👤 VỊ TRÍ 3: DEV LOGIC "SUN" (Xử lý Nắng)
 * Nhiệm vụ: Tra bảng ma trận, cập nhật tài nguyên nếp/lá và đổi thời tiết.
 * LƯU Ý: Dùng con trỏ (*n, *ld, *weather) để thay đổi giá trị gốc.
 * ====================================================================================== */

void handleSun(int *n, int *ld, int dc, int dg, char *weather) {
    // Chỉ chạy nếu thời tiết là "Sun"
    if (strcmp(weather, "Sun") != 0) return;

    // 1. Tra bảng ma trận [5][6] (Hàng: ld%5, Cột: dc%6) để lấy X%
    // int sunTable[5][6] = { ... };
    // int X = ...

    // 2. Cập nhật n và ld (Gọi hàm myRound của Vị trí 2)
    // *n = *n + myRound(...);
    // *ld = *ld - X;

    // 3. Đổi thời tiết dựa trên (dc + dg) % 3
    // strcpy(weather, "...");
    
    // [PHẦN CỦA BẠN: VIẾT CODE HOÀN CHỈNH VÀO ĐÂY]
}

/* ======================================================================================
 * 👤 VỊ TRÍ 4: DEV LOGIC "FOG & CLOUD" (Biến đổi size & Check dừng sớm)
 * Nhiệm vụ: Xử lý Fog (đổi size bánh) và Cloud (Check số bạn bè).
 * ====================================================================================== */

// Hàm 1: Xử lý Fog (Thay đổi kích thước dc, dg)
void handleFog(int *dc, int *dg, char *weather) {
    if (strcmp(weather, "Fog") != 0) return;
    
    // Gọi hàm isFibonacci của Vị trí 2
    // Logic: Nếu cả *dc và *dg là Fib -> Giảm 50%. Ngược lại -> Nhân đôi.
    // [PHẦN CỦA BẠN: VIẾT CODE VÀO ĐÂY]
}

// Hàm 2: Kiểm tra số bạn bè (Cloud) để dừng chương trình
// Output: true nếu là số bạn bè (để main dừng), false nếu không.
bool checkAmicable(int n, int ld, char *weather) {
    if (strcmp(weather, "Cloud") != 0) return false;

    // Gọi hàm sumProperDivisors của Vị trí 2
    // Logic: Kiểm tra cặp (n, ld) có phải số bạn bè không?
    // [PHẦN CỦA BẠN: VIẾT CODE VÀO ĐÂY]
    return false;
}

/* ======================================================================================
 * 👤 VỊ TRÍ 5: DEV CORE (Thuật toán tìm bánh - QUAN TRỌNG NHẤT)
 * Nhiệm vụ: Chạy vòng lặp tìm phương án tối ưu nhất.
 * ====================================================================================== */

void solve(int n, int dc, int dg, int ld, char *weather) {
    // 1. Tính chi phí nếp và lá cho 1 bánh chưng/giầy
    // double rice_chung = ...;
    // int leaf_chung = (dc < 8) ? 1 : 2; ...
    
    // 2. Chạy 2 vòng lặp for (i: bánh chưng, j: bánh giầy)
    // for (int i = 0; ... ) {
    //     for (int j = 0; ... ) {
            // Kiểm tra đủ nếp, đủ lá?
            
            // SO SÁNH TỐI ƯU (Logic cốt lõi):
            // Ưu tiên 1: Nếp dư ít nhất.
            // Ưu tiên 2 (nếu nếp dư bằng nhau) xét theo Weather:
            // - Wind: Max i
            // - Rain: Min abs(i - j)
            // - Fog: Min (i + j)
            // - Cloud: Max j
    //     }
    // }

    // 3. Ghi kết quả tìm được ra file output.out
    // FILE *f = fopen("output.out", "w");
    // fprintf(f, "%d %d %.3f", best_bc, best_bg, min_nd);
    // fclose(f);
}

/* ======================================================================================
 * 👤 VỊ TRÍ 1: TESTER & LEADER (Người ghép code)
 * Nhiệm vụ: Hàm Main quản lý luồng chương trình.
 * ====================================================================================== */

int main() {
    // 1. Khai báo biến
    int n, dc, dg, ld;
    char weather[20];

    // 2. Đọc file input.inp
    FILE *fin = fopen("input.inp", "r");
    if (fin == NULL) return 1;
    fscanf(fin, "%d %d %d %d %s", &n, &dc, &dg, &ld, weather);
    fclose(fin);

    // --- BẮT ĐẦU XỬ LÝ LOGIC (GỌI HÀM CỦA CÁC BẠN) ---

    // Bước 1: Xử lý Nắng (Vị trí 3)
    handleSun(&n, &ld, dc, dg, weather);

    // Bước 2: Xử lý Sương Mù (Vị trí 4)
    handleFog(&dc, &dg, weather);

    // Bước 3: Kiểm tra Số bạn bè - Mây (Vị trí 4)
    if (checkAmicable(n, ld, weather)) {
        // Nếu là số bạn bè, trả hết nếp và DỪNG LUÔN
        FILE *fout = fopen("output.out", "w");
        fprintf(fout, "0 0 %.3f", (double)n);
        fclose(fout);
        return 0; 
    }

    // Bước 4: Chạy thuật toán tìm bánh (Vị trí 5)
    solve(n, dc, dg, ld, weather);

    return 0;
}