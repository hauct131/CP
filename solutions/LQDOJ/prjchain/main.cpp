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

vpii a;
vpii pos, neg;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("PRJCHAIN.INP", "r", stdin);
        freopen("PRJCHAIN.OUT", "w", stdout);
    #endif
}

bool check(int von){
    int cur = von;

    for(auto x : pos){
        int ai = x.F;
        int bi = x.S;

        if(cur < ai) return false;

        cur = cur - ai + bi;
    }

    for(auto x : neg){
        int ai = x.F;
        int bi = x.S;

        if(cur < ai) return false;

        cur = cur - ai + bi;
    }

    return true;
}

void solve(){
    int n; cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].F;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i].S;
    }

    for(int i = 1; i <= n; i++){
        if(a[i].F > a[i].S){
            neg.push_back(a[i]);
        }
        else pos.push_back(a[i]);
    }

    sort(neg.begin(), neg.end(), [](auto x, auto y){
         return x.S > y.S;
         });
    sort(pos.begin(), pos.end(), [](auto x, auto y){
         return x.F < y.F;
         });

    int l = 1, r = 1e18;
    int ans = -1;
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
