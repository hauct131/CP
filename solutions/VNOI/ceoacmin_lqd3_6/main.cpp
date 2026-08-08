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

int t, n, k;

void solve(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n % (k + 1) == 0){
            cout << "Tho Win\n";
        }
        else cout << "Rua Win\n";
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
