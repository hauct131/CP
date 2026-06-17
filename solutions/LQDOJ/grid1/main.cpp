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

int n, m;
char a[1005][1005];

const int MOD = 1e9 + 7;

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    vii dp(n + 1, vi(m + 1, 0));
    ///dp[i][j] is the total number of unique way to reach cell i, j
    ///base case: to make dp[1][1] = 1. we initialize either the cell above dp[0][1]
    ///or the cell to the left dp[1][0] = 1. but not both to void double-couting
    dp[0][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] != '#'){
                (dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD) %= MOD;
            }
            else dp[i][j] = 0;
        }
    }
    cout << dp[n][m] << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
