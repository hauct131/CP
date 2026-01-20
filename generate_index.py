import os

README_FILE = "README.md"
# THEM 'Training', 'bin', 'obj' VAO DANH SACH BO QUA
IGNORE_DIRS = {'.git', '.vscode', 'bin', 'obj', 'Training_Workspace', 'Training', '__pycache__'}

def generate_readme():
    print("Dang quet toan bo kho Code...")
    
    content = "# 🏆 My Competitive Programming Journey\n\n"
    content += "Nơi lưu trữ các bài toán giải thuật từ Codeforces, VNOI, LeetCode...\n\n"
    content += "| STT | Platform | Tên Bài Toán | Code |\n"
    content += "|:---:|:---:|:---|:---:|\n"
    
    count = 0
    root_dir = "."
    
    # Duyệt qua các folder (Codeforces, VNOI...)
    # Sap xep ten Platform theo thu tu Alphabet
    for platform in sorted(os.listdir(root_dir)):
        platform_path = os.path.join(root_dir, platform)
        
        # Chi quet folder, va folder do KHONG nam trong danh sach loai tru
        if os.path.isdir(platform_path) and platform not in IGNORE_DIRS:
            
            # Duyệt qua từng bài toán trong Platform đó
            for problem in sorted(os.listdir(platform_path)):
                problem_path = os.path.join(platform_path, problem)
                
                # Check ky: Phai la folder va khong phai folder rac (bin/obj) cua C++
                if os.path.isdir(problem_path) and problem not in IGNORE_DIRS:
                    count += 1
                    display_name = problem.replace("_", " ")
                    content += f"| {count} | **{platform}** | {display_name} | [Link]({platform}/{problem}) |\n"

    with open(README_FILE, "w", encoding="utf-8") as f:
        f.write(content)
    
    print(f"✅ Da cap nhat README.md (Da loai bo file rac) voi {count} bai toan!")

if __name__ == "__main__":
    generate_readme()
