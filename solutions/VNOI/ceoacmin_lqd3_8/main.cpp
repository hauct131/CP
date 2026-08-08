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

const int MAXN = 2e5+5;

int n, m;
int a[MAXN];
int b[MAXN];

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);

    int res = LLONG_MAX;
    int i = 1;
    int j = 1;
    while(i <= n && j <= m){
        res = min(res, abs(a[i] - b[j]));
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else{
            res = min(res, 0ll);
            break;
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
