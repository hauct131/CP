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

struct p{
    int x, y, z;
};

void solve(){
    cin >> n;
    vector<p> a(n + 1, {0,0,0});
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
    vii dp(n + 1, vi(1, 0)); //dp[i][j] la so niem vui max khi di toi dia diem i va da tham quan
    //hoat dong j o dia diem i - 1
    for(int i = 1; i <= n; i++){
        dp[i][0] =max(dp[i-1][1], dp[i-1][2]) + a[i].x;
        dp[i][1] =max(dp[i-1][0], dp[i-1][2]) + a[i].y;
        dp[i][2] =max(dp[i-1][0], dp[i-1][1]) + a[i].z;
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
}

signed main()
{
    init();

    solve();

    return 0;
}
