#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
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

void solve(){
    int n;
    cin >> n;
    vpii a(n);
    for(int i = 0; i < n; i++){
        a[i].S = i;
        cin >> a[i].F;
    }
    sort(a.begin(), a.end());
    for(auto x : a){
        cout << x.S + 1<< " ";
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
