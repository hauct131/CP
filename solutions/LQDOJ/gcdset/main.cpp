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

int n, k;

void solve(){
    n = k = 0;
    int ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a; cin >> a;

        if(a % k == 0){
            ans = __gcd(a/k, ans);
        }
    }
    if(ans == 1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

signed main()
{
    init();
    int tc; cin >> tc;
    while(tc--)
        solve();

    return 0;
}
