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

int n, m, p, q;

void solve(){
    cin >> n >> m >> p >> q;
    cout << __gcd(abs(p - n), abs(q-m)) - 1 << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
