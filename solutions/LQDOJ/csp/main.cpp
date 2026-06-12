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
vi a;

void solve(){
    cin >> n >> m;
    a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for(int j = 2; j <= n; j++){
        int imax = 0;
        int x = m - a[j];
        int l = 1, r = j - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(a[mid] <= x){
                imax = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans += imax;
    }
    cout << ans << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
