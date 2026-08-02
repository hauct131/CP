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

int n, l, r;

void solve(){
    cin >> n >> l >> r;
    int pre[n + 1];
    int a[n + 1];
    int res = -100000000000;

    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = l; i <= r; i++){
        for(int j = 1; j <= n - i + 1; j++){
            int k = j + i - 1;

            res = max(res, pre[k] - pre[j - 1]);

//            cout << i << " " << j << " " << k  << " " << res << " " << " " << pre[j] << " " << pre[k-1] << " " << pre[j] - pre[k-1]<< endl;
        }
    }
    cout << res;
}

signed main()
{
    init();

    solve();

    return 0;
}
