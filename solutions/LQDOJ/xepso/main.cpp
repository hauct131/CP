#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define endl "\n"

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;

#define F first
#define S second

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

void solve(){
    int n; cin >> n;
    vector<string> s;
    for(int i = 0 ; i < n; i++){
        string tmp; cin >> tmp;
        s.push_back(tmp);
    }
    sort(s.begin(), s.end(), [](string a, string b){
         return a + b > b + a;
         });
    for(auto x : s) cout << x;
}

signed main()
{
    init();

    solve();

    return 0;
}
