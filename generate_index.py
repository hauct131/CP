import os

# Tên file Readme sẽ tạo ra
README_FILE = "README.md"
# Các thư mục muốn bỏ qua (không quét)
IGNORE_DIRS = {'.git', '.vscode', 'bin', 'obj', 'Training_Workspace'}

def generate_readme():
    print("Dang quet toan bo kho Code...")
    
    content = "# 🏆 My Competitive Programming Journey\n\n"
    content += "Nơi lưu trữ các bài toán giải thuật từ Codeforces, VNOI, LeetCode...\n\n"
    content += "| STT | Platform | Tên Bài Toán | Code |\n"
    content += "|:---:|:---:|:---|:---:|\n"
    
    count = 0
    root_dir = "."
    
    # Duyệt qua các folder (Codeforces, VNOI...)
    for platform in sorted(os.listdir(root_dir)):
        platform_path = os.path.join(root_dir, platform)
        
        # Chỉ quét các folder, bỏ qua file lẻ và folder rác
        if os.path.isdir(platform_path) and platform not in IGNORE_DIRS:
            
            # Duyệt qua từng bài toán trong Platform đó
            for problem in sorted(os.listdir(platform_path)):
                problem_path = os.path.join(platform_path, problem)
                
                if os.path.isdir(problem_path):
                    count += 1
                    # Tạo link trỏ tới folder bài toán
                    link = f"[{problem}](./{platform}/{problem})"
                    
                    # Thêm dòng vào bảng
                    # Thay dấu _ thành khoảng trắng cho đẹp
                    display_name = problem.replace("_", " ")
                    content += f"| {count} | **{platform}** | {display_name} | [Link]({platform}/{problem}) |\n"

    # Ghi nội dung vào file README.md
    with open(README_FILE, "w", encoding="utf-8") as f:
        f.write(content)
    
    print(f"✅ Da cap nhat README.md voi {count} bai toan!")

if __name__ == "__main__":
    generate_readme()
