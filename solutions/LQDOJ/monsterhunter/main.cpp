#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> void print_v(vector<T> &v) {
    cout << "{";
    for (auto x : v) cout << x << ",";
    cout << "\b}\n";
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

const int maxn = 2e5+5;
int n, p, h;
char a[maxn];
int res = 1e9;
void Try(int idx, int curP, int curH, int ms){
    if(idx > n){
        res = min(res, ms);
        return;
    }

    if(curP <= 0 || curH <= 0) return;

    if(a[idx] == '#'){
        Try(idx + 1, curP, curH, ms);
    }
    else if(a[idx] == 'P')
        Try(idx + 1, curP + 1, curH, ms);
    else if(a[idx] == 'H')
        Try(idx + 1, curP, curH + 1, ms);
    else{
        if(curP - 1 > 0) Try(idx + 1, curP - 1, curH, ms + 1);
        if(curH - 1 > 0) Try(idx + 1, curP, curH - 1, ms);
    }
}

void solve1() {
    Try(1, p, h, 0);
    cout << (res == 1e9 ? -1 : res) << endl;
}

void solve2() {
    static int dp[205][205][205];
    memset(dp, 0x3f, sizeof(dp));
    const int INF = 0x3f3f3f3f;
    int start_p = min(p, 200);
    int start_h = min(h, 200);
    dp[0][start_p][start_h] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 200; j++) {
            for (int k = 1; k <= 200; k++) {
                if (a[i] == '#') {
                    dp[i][j][k] = dp[i - 1][j][k];
                } else if (a[i] == 'P') {
                    if (j > 1) dp[i][j][k] = dp[i - 1][j - 1][k];
                    if (j == 200) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                } else if (a[i] == 'H') {
                    if (k > 1) dp[i][j][k] = dp[i - 1][j][k - 1];
                    if (k == 200) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                } else if (a[i] == 'M') {
                    if (j < 200) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + 1][k] + 1);
                    if (k < 200) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k + 1]);
                }
            }
        }
    }
    int ans = INF;
    for (int j = 1; j <= 200; j++)
        for (int k = 1; k <= 200; k++)
            ans = min(ans, dp[n][j][k]);

    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
}

void solve3(){
    int m = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 'M') m++;
    }
    if(m > p + h - 2){
        cout << -1 << endl;
        return;
    }
    else cout << max(0, m - h + 1) << endl;
}

void solve4(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == 'P') p++;
        if(a[i] == 'H') h++;
        if(a[i] == 'M'){
            if(h > 1) h--;
            else if(p > 1){
                p--;
                ans++;
            }
            else{
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    init();
    cin >> n >> p >> h;
    for(int i = 1; i <= n; i++) cin >> a[i];
//    if(n < 20 && p < 20 && h < 20) solve1();
    if(n <= 200 && p <= 200 && h <= 200) solve2();
    else{
        solve4();
    }
    return 0;
}
