#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

#define endl "\n"

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int n;
vector<string> s;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string t; cin >> t;
        s.push_back(t);
    }
    sort(s.begin(), s.end(), [](string a, string b){
           return b+a < a+b;
           });
    for(auto x : s) cout << x;

}

signed main()
{
    init();

    solve();

    return 0;
}
