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
vi a, b;

bool check(int R){
    int best;
    for(int i = 1; i <= n; i++){
        best = 1e18;

        auto it = lower_bound(b.begin() + 1, b.end(), a[i]);
        if(it != b.end()){
            best = min(best, abs(*it - a[i]));
        }

        if(it != b.begin() + 1){
            it--;
            best = min(best, abs(*it - a[i]));
        }

        if(best > R) return false;
    }
    return best <= R;
}
void solve(){
    cin >> n >> m;
    a.assign(n + 1, 0);
    b.assign(m + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    int l = 0, r = 1e18;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
