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

vpii a;
int n;
void solve(){
    cin >> n;
    a.assign(n + 1, {0, 0});
    for(int i = 1; i <= n; i++){
       cin >> a[i].F >> a[i].S;
    }
    sort(a.begin() + 1, a.end(), [](pii x, pii y){
         return  x.F < y.F;
         });
    int tmp1 = 1e18;
    for(int i = 1; i < n; i++){
        tmp1 = min(tmp1, abs(a[i].F - a[i+1].F));
    }
    sort(a.begin() + 1, a.end(), [](pii x, pii y){
         return  x.S < y.S;
         });
    int tmp2 = 1e18;
    for(int i = 1; i < n; i++){
        tmp2 = min(tmp2, abs(a[i].S - a[i+1].S));
    }
    cout << min(tmp1, tmp2) << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
