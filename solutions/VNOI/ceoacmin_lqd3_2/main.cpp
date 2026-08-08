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

int n, q;
int a[MAXN];

bool findX(int x){
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a[mid] == x){
            return true;
        }
        else if(x < a[mid]){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return false;
}

void solve(){
    cin >> n >> q;;
    for(int i = 1; i <= n; i++) cin >> a[i];

    while(q--){
        int x; cin >> x;
        if(findX(x)) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
