#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/common_math.h"
#include "../include/logic_weather.h"
#include "../include/logic_solver.h"

// Hàm kiểm tra input Weather có hợp lệ không
int validWeather(const char *w) {
    if (!w) return 0;
    return strcmp(w, "Sun") == 0 ||
           strcmp(w, "Fog") == 0 ||
           strcmp(w, "Rain") == 0 ||
           strcmp(w, "Wind") == 0 ||
           strcmp(w, "Cloud") == 0;
}

int main() {
    // Dùng double để đọc nếp (phòng trường hợp input là số thực), sau đó ép kiểu nếu cần
    double n_temp; 
    int n, dc, dg, ld;
    char weather[50];

    // 1. Đọc file Input
    FILE *fi = fopen("input.inp", "r");
    if (!fi) {
        // Lỗi không mở được file -> In ra -1 -1 0
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "-1 -1 0.000"); fclose(fo); }
        return 0;
    }

    // Đọc 5 tham số
    if (fscanf(fi, "%lf %d %d %d %49s", &n_temp, &dc, &dg, &ld, weather) != 5) {
        fclose(fi);
        FILE *fo = fopen("output.out", "w");
        // Lỗi định dạng -> In ra -1 -1 n
        if (fo) { fprintf(fo, "-1 -1 %.3f", n_temp); fclose(fo); }
        return 0;
    }
    fclose(fi);

    // Chuyển n về int (vì đề bài nếp thường là nguyên, nhưng biến nd là float)
    n = (int)n_temp;

    // 2. Validate dữ liệu đầu vào (Input check)
    if (n <= 0 || ld <= 0 || (dc == 0 && dg == 0) || !validWeather(weather)) {
        FILE *fo = fopen("output.out", "w");
        if (fo) { fprintf(fo, "-1 -1 %.3f", n_temp); fclose(fo); }
        return 0;
    }

    // 3. Gọi các module xử lý (Logic Flow)
    
    // Bước 1: Xử lý Nắng (Thay đổi n, ld, weather)
    handleSun(&n, &ld, dc, dg, weather);

    // Bước 2: Xử lý Sương mù (Thay đổi dc, dg)
    handleFog(&dc, &dg, weather);

    // Bước 3: Kiểm tra Số bạn bè (Mây) -> Dừng sớm nếu đúng
    if (checkAmicable(n, ld, weather)) {
        FILE *fo = fopen("output.out", "w");
        // Trả về 0 0 n (đúng định dạng %.3f)
        if (fo) { fprintf(fo, "0 0 %.3f", (double)n); fclose(fo); }
        return 0;
    }

    // Bước 4: Chuyển giao cho ông Solver tính toán và ghi file
    // Lưu ý: Hàm solve này nằm trong file src/logic_solver.c
    solve(n, dc, dg, ld, weather);

    return 0;
}
