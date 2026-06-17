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
vi a;

void solve(){
    cin >> n;
    a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vi dp(n + 1, 1e18); //dp[i] la chi phi toi thieu khi nhay toi hon da thu i
    dp[1] = 0;
    dp[2] = abs(a[2] - a[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]), dp[i-2] + abs(a[i] - a[i-2]));
    }
    cout << dp[n];
}

signed main()
{
    init();

    solve();

    return 0;
}
