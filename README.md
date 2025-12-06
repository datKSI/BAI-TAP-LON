=========================================================================
          HƯỚNG DẪN DỰ ÁN BANH CHUNG OS (OPEN SOURCE V4.0)
=========================================================================

1. YÊU CẦU CÀI ĐẶT (PREREQUISITES)
-------------------------------------------------------------------------
Trước khi bắt đầu, hãy cài đủ các Extensions sau trên VS Code:
1. C/C++ (Microsoft) -> Để code C và gợi ý lệnh.
2. Makefile Tools (Microsoft) -> QUAN TRỌNG: Để VS Code hiểu lệnh 'make'.
3. Live Share (Microsoft) -> Nếu muốn code chung thời gian thực.

*LƯU Ý: Nếu không muốn cài đặt lằng nhằng trên máy, hãy dùng GITHUB CODESPACES.

2. CẤU TRÚC THƯ MỤC
-------------------------------------------------------------------------
/PROJECT_ROOT
  ├── include/         -> CHỨA FILE HEADER (.h)
  ├── src/             -> CHỨA SOURCE CODE (.c)
  ├── Makefile         -> ROBOT BIÊN DỊCH (Gõ lệnh 'make' là chạy)
  └── input.inp        -> DỮ LIỆU TEST (Thay số vào đây để thử)

3. VAI TRÒ FILE HEADER (.h) - USER-DEFINED FUNCTIONS
-------------------------------------------------------------------------
Thư mục include/ chứa các file .h. Đây là nơi chứa:
- KHAI BÁO NGUYÊN MẪU HÀM (Function Prototypes): Chỉ liệt kê tên hàm.
- Giúp các file .c gọi chéo nhau mà không cần biết nội dung bên trong.

4. PHÂN CÔNG NHIỆM VỤ (TRONG THƯ MỤC SRC/)
-------------------------------------------------------------------------
[A] main.c (LEADER)
    - File "Tổng quản". Đọc input -> Gọi hàm xử lý -> Ghi output.

[B] common_math.c (DEV TOÁN)
    - Định nghĩa chi tiết các hàm toán: Fibonacci, tổng ước số...

[C] logic_weather.c (DEV THỜI TIẾT)
    - Định nghĩa chi tiết hàm xử lý: Tra bảng Nắng, Fog, Cloud.

[D] logic_solver.c (DEV THUẬT TOÁN)
    - Định nghĩa chi tiết hàm thuật toán: Vòng lặp vét cạn tìm số bánh.

5. QUY TRÌNH LÀM VIỆC & CHẠY CODE (DAILY WORKFLOW)
-------------------------------------------------------------------------
Dưới đây là quy trình 4 bước mỗi khi ngồi vào bàn làm việc:

BƯỚC 1: LẤY CODE MỚI NHẤT TỪ GITHUB
   - Mở Terminal (Ctrl + `).
   - Nếu là lần đầu tiên:
       git clone https://github.com/datKSI/BAI-TAP-LON.git
   - Nếu đã có code rồi (làm việc hàng ngày):
       git pull origin main

BƯỚC 2: SỬA CODE & BIÊN DỊCH (BUILD)
   - Vào thư mục /src sửa file của mình.
   - Nhớ bấm Ctrl + S (hoặc Cmd + S) để lưu file.
   - Gõ lệnh biên dịch:
       make

BƯỚC 3: CHẠY THỬ (RUN TEST)
   - Gõ lệnh chạy chương trình:
       ./banhchung_app       (Máy MacOS / Linux)
       .\banhchung_app.exe   (Máy Windows)
   - Mở file 'output.out' kiểm tra xem kết quả đúng chưa.

BƯỚC 4: LƯU & GỬI CODE LÊN GITHUB (PUSH)
   - Gõ lần lượt 3 lệnh sau:
       git add .
       git commit -m "Ghi chú ngắn gọn về việc đã sửa"
       git push origin main
       
   - ⚠️ QUAN TRỌNG: Nếu lệnh trên báo lỗi (rejected) hoặc mạng lag, dùng lệnh mạnh này để ÉP code lên:
       git push -f origin main

-------------------------------------------------------------------------
⚠️ QUY TẮC AN TOÀN:
- Trước khi sửa code, LUÔN LUÔN gõ 'git pull' để tránh xung đột.
- Không sửa file của người khác nếu không cần thiết.