=========================================================================
          HƯỚNG DẪN DỰ ÁN BANH CHUNG OS (OPEN SOURCE V4.0)
=========================================================================

1. YÊU CẦU CÀI ĐẶT (PREREQUISITES)
-------------------------------------------------------------------------
Trước khi code, hãy cài đủ các Extensions sau trên VS Code:
1. C/C++ (Microsoft) -> Để code C và gợi ý lệnh.
2. Makefile Tools (Microsoft) -> QUAN TRỌNG: Để VS Code hiểu file Makefile.
3. Live Share (Microsoft) -> Nếu muốn code chung thời gian thực.

2. CẤU TRÚC THƯ MỤC TỔNG QUÁT
-------------------------------------------------------------------------
/PROJECT_ROOT
  ├── include/         -> CHỨA "BẢN VẼ" (File .h - Khai báo tên hàm)
  ├── src/             -> CHỨA "CODE THẬT" (File .c - Xử lý logic)
  ├── Makefile         -> ROBOT BIÊN DỊCH (Gõ lệnh 'make' là chạy)
  └── input.inp        -> DỮ LIỆU TEST (Thay số vào đây để thử)

3. PHÂN CÔNG NHIỆM VỤ (TRONG THƯ MỤC SRC/)
-------------------------------------------------------------------------
[A] main.c (LEADER)
    - Là file "Tổng quản".
    - Nhiệm vụ: Đọc input.inp -> Gọi lần lượt các ông B, C, D -> Ghi output.out.

[B] common_math.c (DEV TOÁN)
    - Là "Kho công cụ toán học".
    - Nhiệm vụ: Chứa hàm kiểm tra Fibonacci, tính tổng ước số, làm tròn...
    - Các file khác muốn tính toán gì thì gọi hàm trong này.

[C] logic_weather.c (DEV THỜI TIẾT)
    - Là "Bộ xử lý biến đổi".
    - Nhiệm vụ: Tra bảng Nắng, nhân đôi/chia đôi (Fog), check số bạn bè (Cloud).
    - Input đi qua đây sẽ bị thay đổi giá trị trước khi tính toán.

[D] logic_solver.c (DEV THUẬT TOÁN)
    - Là "Trái tim xử lý" (Nặng nhất).
    - Nhiệm vụ: Chạy 2 vòng lặp vét cạn (Brute-force) để tìm số bánh tối ưu.
    - Áp dụng các ưu tiên: Nếp dư min -> Ưu tiên theo Weather.

4. QUY TRÌNH DỮ LIỆU CHẠY (DATA FLOW)
-------------------------------------------------------------------------
INPUT (input.inp) 
   ⬇
LEADER (main.c) đọc dữ liệu
   ⬇
WEATHER (logic_weather.c) biến đổi dữ liệu (gọi Math để check)
   ⬇
SOLVER (logic_solver.c) tính toán tìm kết quả
   ⬇
OUTPUT (output.out)

5. HƯỚNG DẪN CHẠY CODE (RUNNING)
-------------------------------------------------------------------------
Bước 1: Mở Terminal trong VS Code (Ctrl + `).
Bước 2: Gõ lệnh:
    make
    (Lệnh này sẽ gọi gcc để biên dịch toàn bộ file trong /src)

Bước 3: Gõ lệnh chạy chương trình:
    ./banhchung_app       (Nếu dùng MacOS / Linux / Git Bash)
    .\banhchung_app.exe   (Nếu dùng Windows PowerShell)

Bước 4: Mở file 'output.out' để xem kết quả.

6. QUY TRÌNH LÀM VIỆC NHÓM VỚI GIT (WORKFLOW)
-------------------------------------------------------------------------
Lần đầu tiên tham gia:
   git clone https://github.com/datKSI/BAI-TAP-LON.git

Mỗi khi bắt đầu làm việc (Để lấy code mới nhất của anh em về):
   git pull origin main

Sau khi code xong và muốn gửi lên:
   git add .
   git commit -m "Ghi chú ngắn gọn về việc đã làm"
   git push origin main

LƯU Ý CUỐI CÙNG:
- Không sửa file của người khác nếu không cần thiết.
- Nếu gõ 'make' bị lỗi -> Kiểm tra lại Extension 'Makefile Tools' hoặc cài đặt GCC.
