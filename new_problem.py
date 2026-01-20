import os

# DANH SÁCH NỀN TẢNG HỖ TRỢ (Bạn có thể thêm vào đây tùy thích)
PLATFORMS = [
    "Codeforces",
    "VNOI",
    "AtCoder",
    "CSES",
    "LeetCode",
    "HackerRank",
    "Spoj",
    "Kattis",
    "Khac" # Dành cho đề thi HSG, đề thầy cho...
]

# TEMPLATE CODE
CPP_TEMPLATE = """/*
 * PROBLEM: {problem_name}
 * LINK: {link}
 * -------------------------
 * TÓM TẮT ĐỀ:
 * PHÂN TÍCH SUBTASKS:
 * - Subtask 1 (Naive): 
 * CHIẾN THUẬT ({approach}):
 * - State: ...
 * -------------------------
 * COMPLEXITY: O(...)
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

void solve() {{
    // Code here
}}

int main() {{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}}
"""

def create_problem():
    print("\n--- 🌏 KHOI TAO BAI TOAN DA NEN TANG ---")
    
    # 1. Menu chọn Platform
    print("Chon nen tang ban dang luyen tap:")
    for i, p in enumerate(PLATFORMS):
        print(f"  {i+1}. {p}")
    
    try:
        choice = int(input("Nhap so thu tu (1-{}): ".format(len(PLATFORMS))))
        if 1 <= choice <= len(PLATFORMS):
            platform = PLATFORMS[choice-1]
        else:
            print("❌ Lua chon khong hop le!")
            return
    except ValueError:
        print("❌ Vui long nhap so!")
        return

    # 2. Nhập thông tin bài
    problem_name = input(f"Nhap ten bai toan tren {platform}: ").strip()
    link_url = input("Link bai toan (Enter de bo qua): ").strip()
    
    # Xử lý tên folder
    clean_name = problem_name.replace(" ", "_")
    
    # Đường dẫn: Platform/Ten_Bai
    # Script tự động tạo folder Platform nếu chưa có
    path = os.path.join(platform, clean_name)
    
    if os.path.exists(path):
        print(f"⚠️  Bai nay da ton tai trong thu muc {platform}!")
        return
    
    try:
        os.makedirs(path)
        print(f"✅ Da tao folder: {path}")
            
        # Tạo file Full
        with open(os.path.join(path, f"{clean_name}_Full.cpp"), "w", encoding="utf-8") as f:
            f.write(CPP_TEMPLATE.format(problem_name=problem_name, link=link_url, approach="Optimized"))
            
        print("\n🚀 Sẵn sàng code! Folder đã được tạo đúng chỗ.")
        
    except OSError as e:
        print(f"❌ Loi he thong: {e}")

if __name__ == "__main__":
    create_problem()
