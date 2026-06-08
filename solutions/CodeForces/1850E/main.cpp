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

int n, c;
vi a;

bool check(int w){
    int s = 0;
    for(int i = 1; i <= n; i++){
        s += 1ll*(a[i] + 2*w) * (a[i] + 2*w);
        if(s > c) return false;
    }

    return true;
}
void solve(){
    cin >> n >> c;
    a.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e9;
    int ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}

signed main()
{
    init();
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
