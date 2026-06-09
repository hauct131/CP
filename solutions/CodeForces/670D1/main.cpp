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
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
}

const int MAXN = 100000 + 5;

int n, k;
int a[MAXN], b[MAXN];

bool check(int w) {
    int need = 0;

    for(int i = 1; i <= n; i++) {
        int required = a[i] * w;

        if(required > b[i]) {
            need += required - b[i];
        }

        if(need > k) return false;
    }

    return need <= k;
}

void solve() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int l = 0, r = 2000000000;
    int ans = 0;

    while(l <= r) {
        int mid = (l + r) >> 1;

        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
