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

const int MAXN = 2e5+10;
int n;
int a[MAXN], b[MAXN];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    int res = LLONG_MAX;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(int i = 1; i < n; i++){
        res = min({res, abs(a[i] - a[i+1]), abs(b[i] - b[i+1])});
    }
    cout << res;
}

signed main()
{
    init();

    solve();

    return 0;
}
