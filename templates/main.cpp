#include <bits/stdc++.h>
using namespace std;

// Để chuyển giữa đọc file và nhập từ bàn phím, chỉ cần comment/uncomment dòng sau:
#define FILE_IO

void solve() {
    // CODE CỦA BẠN Ở ĐÂY
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef FILE_IO
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    solve();
    return 0;
}
