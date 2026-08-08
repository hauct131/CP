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

const int MAXN = 1e6+5;
int n, m;
int a[MAXN];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int res = 0;
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n; i++){
        int target = m - a[i];
        int idx = upper_bound(a + i + 1, a + 1 + n, target) - a;
        res += idx - 1 - (i + 1) + 1;
    }
    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
