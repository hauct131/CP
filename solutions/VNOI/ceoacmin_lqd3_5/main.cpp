#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define endl "\n"

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<pii> vpii;

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

const int MAXN = 1e5+5;
int n, k;
int a[MAXN];
int pre[MAXN];

void solve(){
    cin >> n >> k;
    int m = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        m = max(m, a[i]);
        pre[i] = pre[i-1] + a[i];
    }
    cout << pre[n] - min(m, k) + 1;
//    int idx = upper_bound(a + 1, a + 1 + n, k) - a;
//    int tmp = LLONG_MIN;
//    if(idx > n) tmp = max(tmp, a[n]);
//    else{
//        tmp = k;
//    }
//    cout << pre[n] - tmp + 1;


}

signed main()
{
    init();

    solve();

    return 0;
}
