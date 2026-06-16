#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define endl "\n"

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<pii> vpii;

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

int n, w;
vpii a;

void solve(){
    cin >> n >> w;
    a.assign(n + 1, {0, 0});
    for(int i = 1; i <= n; i++){
        cin >> a[i].F >> a[i].S;
    }
    vii dp(n + 1, vi(w + 1, 0)); //dp[i][j]: gia tri lon nhat khi xet toi vat thu i
    //co can nang tui la j
    for(int i = 1; i <= n; i++){
        int weight = a[i].F;
        int v = a[i].S;
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            if(j - weight >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-weight] + v);
            }
        }
    }
    cout << dp[n][w] << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
