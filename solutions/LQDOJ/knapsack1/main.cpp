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

vpii a;
int n, k;

void solve(){
    cin >> n >> k;
    a.resize(n + 1, {0, 0});
    for(int i = 1; i <= n; i++){
        cin >> a[i].F >> a[i].S;
    }
    vii dp(2, vi(k + 1, 0)); //dp[i][j] lay i do vat dau tien va gia tri cua tui la j
    for(int i = 1; i <= n; i++){
        int w = a[i].F;
        int v = a[i].S;

        int cur = i % 2;
        int prv = (i - 1) % 2;

        for(int j = 0; j <= k; j++){
            dp[cur][j] = dp[prv][j];
            if(w <= j){
                dp[cur][j] = max(dp[cur][j], dp[prv][j-w] + v);
            }
        }
    }
    cout << dp[n%2][k] << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
