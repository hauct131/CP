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
int n, m, k;

int side(int len, int h) {
    int t = min(len, h - 1);
    return t * h - t * (t + 1) / 2;
}

bool check(int h) {
    int need = h + side(k - 1, h) + side(n - k, h);
    return need <= m;
}

void solve(){
    cin >> n >> m >> k;

    int l = 1, r = m;
    int ans = 1;
    while(l <= r){
        int mid = (l + r) >> 1;

        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << m - ans << endl;
}

signed main()
{
    init();

    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}
