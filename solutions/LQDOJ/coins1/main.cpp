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

int n;
vector<double> a;
void solve(){
    cin >> n;
    a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<double>> dp(n + 1, vector<double>(3005, 0));
    //dp[i][j] is the probability of exactly j heads until first i coins
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i-1][j]*(1-a[i]);
            if(j > 0) dp[i][j] += dp[i-1][j-1]*a[i];
        }
    }
    for(int i = n/2 + 1; i <= n; i++) dp[n][3004] += dp[n][i];
    cout << fixed << setprecision(10) << dp[n][3004] << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
