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

const int MAXN = 1e5+5;
int n, k;
int a[MAXN];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> mp;
//    mp[0] = 1;
    int res = 0;
    for(int i = 1; i <= n; i++){
        mp[a[i]]++;

        int target = k - 1ll*a[i]*a[i];
        if(mp.count(target) > 0){
            res += mp[target];
        }
    }
    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
