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

bool check(int x){
    int c = 0;
    for(int i = 1; i <= n; i++){
        c += (a[i] - 1)/x;
        if(c > k) return false;
    }
    return c <= k;
}

void solve(){
    cin >> n >> k;
    a.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int l = 1, r = a[n];
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}

signed main()
{
    init();

    solve();

    return 0;
}
