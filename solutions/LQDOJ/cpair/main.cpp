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

void solve(){
    cin >> n >> k;
    a.assign(n + 1, 0);
    map<int, int> mp;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        mp[a[i]]++;
        ans += mp[k - a[i]*a[i]];
    }
    cout << ans << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
