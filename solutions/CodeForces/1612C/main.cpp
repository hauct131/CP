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
int k, x;

int sum(int z){
    if(z <= k) {
        return z * (z + 1) / 2;
    }

    int f = k * (k + 1) / 2;

    int t = z - k;

    int s = t * k - t * (t + 1) / 2;

    return f + s;
}

bool check(int z){
    return sum(z) >= x;
}

void solve(){
    cin >> k >> x;
    int total = k * k;
    if(x >= total){
        cout << 2*k - 1 << endl;
        return;
    }
    int l = 1, r = 2*k-1;
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
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
