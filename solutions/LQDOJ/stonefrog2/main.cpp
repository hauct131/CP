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

int n, k;
vi a;

void solve(){
    cin >> n >> k;
    a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vi dp(n + 1, 1e18);
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i >= j){
                dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i - j]));
            }
        }
    }
    cout << dp[n] << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
