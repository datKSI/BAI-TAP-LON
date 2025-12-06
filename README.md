=========================================================================
          HƯỚNG DẪN DỰ ÁN BANH CHUNG OS (OPEN SOURCE V4.0)
=========================================================================

1. YÊU CẦU CÀI ĐẶT (PREREQUISITES)
-------------------------------------------------------------------------
Trước khi bắt đầu, hãy cài đủ các Extensions sau trên VS Code:
1. C/C++ (Microsoft) -> Để code C và gợi ý lệnh.
2. Makefile Tools (Microsoft) -> QUAN TRỌNG: Để VS Code hiểu lệnh 'make'.
3. Live Share (Microsoft) -> Nếu muốn code chung thời gian thực.

*LƯU Ý: Nếu không muốn cài đặt lằng nhằng trên máy, hãy dùng GITHUB CODESPACES
(Vào link GitHub -> Bấm nút Code xanh lá -> Chọn tab Codespaces -> Create).

2. CẤU TRÚC THƯ MỤC
-------------------------------------------------------------------------
/PROJECT_ROOT
  ├── include/         -> CHỨA "BẢN VẼ" (File .h - Khai báo tên hàm)
  ├── src/             -> CHỨA "CODE THẬT" (File .c - Xử lý logic)
  ├── Makefile         -> ROBOT BIÊN DỊCH (Gõ lệnh 'make' là chạy)
  └── input.inp        -> DỮ LIỆU TEST (Thay số vào đây để thử)

3. PHÂN CÔNG NHIỆM VỤ (TRONG THƯ MỤC SRC/)
-------------------------------------------------------------------------
[A] main.c (LEADER)
    - File "Tổng quản". Đọc input -> Gọi hàm xử lý -> Ghi output.

[B] common_math.c (DEV TOÁN)
    - Kho công cụ toán: Fibonacci, tổng ước số, làm tròn...

[C] logic_weather.c (DEV THỜI TIẾT)
    - Xử lý biến đổi: Tra bảng Nắng, Fog (Fibonacci), Cloud (Số bạn bè).

[D] logic_solver.c (DEV THUẬT TOÁN)
    - Trái tim xử lý: Chạy vòng lặp vét cạn tìm số bánh tối ưu.

4. QUY TRÌNH LÀM VIỆC & CHẠY CODE (DAILY WORKFLOW)
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
   - Sau khi sửa xong, gõ lệnh biên dịch:
       make
   - Nếu không báo lỗi gì tức là biên dịch thành công.

BƯỚC 3: CHẠY THỬ (RUN TEST)
   - Gõ lệnh chạy chương trình:
       ./banhchung_app       (Máy MacOS / Linux / Codespaces)
       .\banhchung_app.exe   (Máy Windows)
   - Mở file 'output.out' kiểm tra xem kết quả đúng chưa.

BƯỚC 4: LƯU & GỬI CODE LÊN GITHUB (PUSH)
   - Nếu code đã chạy ngon, hãy gửi lên cho anh em dùng:
       git add .
       git commit -m "Ghi chú ngắn gọn (VD: Da fix loi ham Fibonacci)"
       git push origin main

-------------------------------------------------------------------------
⚠️ QUY TẮC AN TOÀN:
- Trước khi sửa code, LUÔN LUÔN gõ 'git pull' để tránh xung đột.
- Không sửa file của người khác nếu không cần thiết.
- Nếu gõ 'make' bị lỗi: Kiểm tra lại xem đã cài GCC hoặc Extension chưa.
