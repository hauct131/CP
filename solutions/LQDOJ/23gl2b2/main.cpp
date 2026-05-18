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

const int maxn = 2e5 + 5;
const int mod = 1e9+7;
int n;
int a[maxn];
int pre[maxn];
void solve(){
    int ans = 0;
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            (ans += (a[i] * a[j])%mod) %=mod;
        }
    }

    cout << ans << endl;
}

void solve2(){
    int ans = 0;
    pre[0] = 0;
    cin >> n;
    for(int i = 1 ; i <= n; i++){
        cin >> a[i];
        pre[i] = (pre[i-1] + a[i]) % mod;
    }

    for(int i = n; i >= 1; i--){
        (ans += (a[i] * (pre[i-1] - pre[0]))%mod) %=mod;
    }
    cout << ans << endl;
}

signed main()
{
    init();
//    solve();

    solve2();

    return 0;
}
