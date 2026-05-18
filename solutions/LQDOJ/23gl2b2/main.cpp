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

const int maxn = 1e5;
const int mod = 1e9+7;
int n;
int a[maxn];
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

signed main()
{
    init();

    solve();

    return 0;
}
