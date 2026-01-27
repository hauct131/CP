/*
 * PROBLEM: monsterhunter
 * LINK: https://lqdoj.edu.vn/problem/monsterhunter
 * -------------------------
 * TÓM TẮT ĐỀ:
 * PHÂN TÍCH SUBTASKS:
 * - Subtask 1 (Naive):
 * CHIẾN THUẬT (Optimized):
 * - State: ...
 * -------------------------
 * COMPLEXITY: O(...)
 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

#define endl "\n"
const int INF = 1e18;

int n, p, h;
string s;
int res = INF;

void Try(int idx, int curP, int curH, int cnt){
    if(cnt >= res) return;

    if(idx > n){
        res = min(res, cnt);
        return;
    }

    if(s[idx] == '#') Try(idx + 1, curP, curH, cnt);
    else if(s[idx] == 'P') Try(idx + 1, curP + 1, curH, cnt);
    else if(s[idx] == 'H') Try(idx + 1, curP, curH + 1, cnt);
    else if(s[idx] == 'M'){
        if(curP - 1 > 0) Try(idx + 1, curP - 1, curH, cnt + 1);
        if(curH - 1 > 0) Try(idx + 1, curP, curH - 1, cnt);
    }
}
void solve(){
    cin >> n >> p >> h; cin.ignore();
    cin >> s;
    s = '#' + s;
    Try(1, p, h, 0);
    cout << (res == INF ? -1 : res);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("/home/hao/Olympic/input.txt", "r")) {
        freopen("/home/hao/Olympic/input.txt", "r", stdin);
        freopen("/home/hao/Olympic/output.txt", "w", stdout);
    }

    solve();

    return 0;
}
