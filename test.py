import os
import subprocess
import shutil

# --- CẤU HÌNH (SỬA NẾU CẦN) ---
TEST_DIR = "sample testcases"  # Tên thư mục chứa 23 case
EXE_PATH = "./banhchung_app"   # Tên file chạy C (Windows thì sửa thành "banhchung_app.exe")
INPUT_FILENAME = "input.inp"   # Tên file input bên trong các folder 1, 2...
OUTPUT_FILENAME = "output.out" # Tên file đáp án bên trong các folder 1, 2...

# Màu sắc cho đẹp
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

def compare_results(user_out_path, expected_out_path):
    """So sánh kết quả của bạn và của thầy"""
    try:
        if not os.path.exists(user_out_path): return False
        
        with open(user_out_path, 'r') as f1, open(expected_out_path, 'r') as f2:
            u_line = f1.read().strip().split()
            e_line = f2.read().strip().split()

        if len(u_line) < 3 or len(e_line) < 3: return False

        # So sánh 2 số đầu (Bánh chưng, Bánh giầy) - Phải giống hệt
        if int(u_line[0]) != int(e_line[0]) or int(u_line[1]) != int(e_line[1]):
            return False

        # So sánh số cuối (Nếp dư) - Chấp nhận sai số nhỏ (epsilon)
        u_nep = float(u_line[2])
        e_nep = float(e_line[2])
        if abs(u_nep - e_nep) > 0.01: # Cho phép sai số 0.01
            return False
            
        return True
    except Exception as e:
        return False

def run_tests():
    # 1. Biên dịch code C trước
    print("🔨 Đang biên dịch code C...")
    if os.system("make") != 0:
        print(f"{RED}Lỗi biên dịch! Kiểm tra lại code C.{RESET}")
        return

    # 2. Lấy danh sách các folder con (1, 2, 3...)
    try:
        cases = [d for d in os.listdir(TEST_DIR) if os.path.isdir(os.path.join(TEST_DIR, d))]
        # Sắp xếp theo số thứ tự (1, 2, 10 thay vì 1, 10, 2)
        cases.sort(key=lambda x: int(x) if x.isdigit() else 999)
    except FileNotFoundError:
        print(f"{RED}Không tìm thấy thư mục '{TEST_DIR}'. Hãy kiểm tra lại đường dẫn.{RESET}")
        return

    total = len(cases)
    passed = 0

    print(f"\n🚀 BẮT ĐẦU CHẠY {total} TEST CASE...\n")

    for case in cases:
        case_path = os.path.join(TEST_DIR, case)
        case_input = os.path.join(case_path, INPUT_FILENAME)
        case_expected = os.path.join(case_path, OUTPUT_FILENAME)

        # Kiểm tra xem folder này có đủ file không
        if not os.path.exists(case_input) or not os.path.exists(case_expected):
            print(f"⚠️  Case {case}: Thiếu file input hoặc output. Bỏ qua.")
            continue

        # A. Copy file input của case này ra ngoài để chương trình C đọc
        shutil.copy(case_input, "input.inp")

        # B. Chạy chương trình C
        try:
            # Chạy file exe, chờ nó chạy xong
            subprocess.run([EXE_PATH], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        except Exception:
            print(f"{RED}❌ Case {case}: CRASH (Lỗi chạy chương trình){RESET}")
            continue

        # C. So sánh output.out vừa tạo ra với output chuẩn
        if compare_results("output.out", case_expected):
            print(f"{GREEN}✅ Case {case}: PASS{RESET}")
            passed += 1
        else:
            # Đọc để in ra lỗi
            with open("output.out", 'r') as f: u_out = f.read().strip()
            with open(case_expected, 'r') as f: e_out = f.read().strip()
            print(f"{RED}❌ Case {case}: FAIL{RESET}")
            print(f"   Expected: {e_out}")
            print(f"   Got     : {u_out}")

    print("-" * 40)
    print(f"KẾT QUẢ: {passed}/{total} Case đúng.")
    if passed == total:
        print(f"{GREEN}🏆 TUYỆT VỜI! 10 ĐIỂM VỀ CHỖ!{RESET}")
    else:
        print(f"{RED}💀 Vẫn còn lỗi, cần fix lại code C.{RESET}")

if __name__ == "__main__":
    run_tests()