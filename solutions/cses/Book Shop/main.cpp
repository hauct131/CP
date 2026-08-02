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

int n, t;
const int MAXN = 1e3+10;
vpii a;

void solve(){
    cin >> n >> t;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].F;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].S;
    }
    int res = 0;
    int dp[2][t + 1];
    for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= t; j++) dp[i][j] = -1000000000000;

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int cur = i % 2;
        int pre = (i - 1) % 2;
        for(int j = 0; j <= t; j++){
            dp[cur][j] = dp[pre][j];
            if(j >= a[i].F){
                dp[cur][j] = max(dp[cur][j], dp[pre][j-a[i].F] + a[i].S);
            }
        }
    }
    int last = n % 2;
    for(int i = 0; i <= t; i++){
        res = max(res, dp[last][i]);
    }
    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
