#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define F first
#define S second

#define endl "\n"

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int n;
vector<pair<int, int>> a;

void solve(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].F;
    }

    for(int i = 0; i < n; i++){
        cin >> a[i].S;
    }

    sort(a.begin(), a.end(), [](auto x, auto y){
            return x.S * y.F < y.S * x.F;
         });

//    for(auto x : a) cout << x.F << " " << x.S << endl;
    int res = 0;
    int day = 0;
    for(int i = 0; i < n; i++){
        day += a[i].S;
        res += day*a[i].F;
    }
    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
