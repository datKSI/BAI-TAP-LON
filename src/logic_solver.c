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
    int best_bc = 0;             
    int best_bg = 0;             
    double min_nd = (double)n;
    int best_compare_value = -100;
    // TODO 1: Tính toán chi phí nguyên liệu cho 1 cái bánh.
     // - Nếp cho bánh chưng (dc^2) và bánh giầy (dg^2 * PI / 3).
    [cite_start]
    double rice_chung =(double)dc*dc*sqrt((double)dc); // cong thuc tinh nep chung
    [cite_start]
    double rice_giay =((double)dg*dg*PI)/3;// cong thuc tinh nep giay
    // - Lá dong (1 hoặc 2 lá tùy kích thước).
    [cite_start]// so la can dung
    int leaf_chung =(dc <8) ? 1:2; 
    int leaf_giay =(dg <5) ? 1:2;
    // - Lưu ý: Xử lý trường hợp kích thước = 0 để tránh chia cho 0.
    // TODO 2: Xác định giới hạn vòng lặp (Max số bánh có thể nấu).
    int max_i =(rice_chung >0) ? (int)(n/rice_chung)+1:n;
    if (max_i>n) max_i=n; 
    int max_j =(rice_giay >0) ? (int)(n/rice_giay)+1:n;
    if (max_j>n) max_j=n;
   
    // Biến lưu kết quả tốt nhất (Best Solution)
    int best_bc = 0, best_bg = 0;
    
    // TODO 3: Viết 2 vòng lặp lồng nhau (for i, for j).
    // - Duyệt tất cả khả năng số bánh chưng (i) và bánh giầy (j).
[cite_start]
    for (int i=0;i<=n:i++){
    for (int j=0;j<=n:j++){
        double current_rice_used=(i*rice_chung)+(j*rice_giay);
        int current_leaf_used=(i*leaf_chung)+(j*leaf_giay);
    // - Kiểm tra điều kiện: Đủ nếp và đủ lá không?
    // - Nếu đủ, tính số nếp dư.
        if (current_rice_used <= (double)n && current_leaf_used <= ld) {
        double current_nd = (double)n - current_rice_used;

    // TODO 4: So sánh để tìm phương án tối ưu (Logic khó nhất).
    int chuyenDoiDuong(int x){ 
    if(x<0) return -x; return x; }
    int soSanhLuaChon(int i1,int j1,int nepDu1,int i2,int j2,int nepDu2,int thoiTiet){
    // - Ưu tiên 1: Số nếp dư phải ít nhất (Min).
    if(nepDu1<nepDu2) return -1;
    if(nepDu1>nepDu2) return 1;
    // - Ưu tiên 2 (Khi nếp dư bằng nhau): Xét theo Weather.
         switch(thoiTiet){
    //      + Wind: Chọn phương án có nhiều Bánh Chưng nhất.
        case 1:
            if(i1>i2) return -1;
            if(i1<i2) return 1;
            return 0;
    //      + Rain: Chọn phương án cân bằng nhất (abs(bc-bg) min).
        case 2:
            if(chuyenDoiDuong(i1-j1)<chuyenDoiDuong(i2-j2)) return -1;
            if(chuyenDoiDuong(i1-j1)>chuyenDoiDuong(i2-j2)) return 1;
            return 0;
   //      + Fog: Chọn tổng số bánh ít nhất.
        case 3:
            if(i1+j1<i2+j2) return -1;
            if(i1+j1>i2+j2) return 1;
            return 0;
  //      + Cloud: Chọn phương án có nhiều Bánh Giầy nhất.
        case 4:
            if(j1>j2) return -1;
            if(j1<j2) return 1;
            return 0;
    }
    return 0;
}
            }
        }
    }
}
    // TODO 5: Ghi kết quả tìm được (best_bc, best_bg, min_nd) vào file output.out.
    // Lưu ý định dạng in ra file phải chuẩn theo đề bài.
FILE *fout = fopen("output.out", "w");
    if (fout != NULL) {
        [cite_start]
        fprintf(fout, "%d %d %.3f", best_bc, best_bg, min_nd);
        fclose(fout);
}
