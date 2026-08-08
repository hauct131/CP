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

int n, q;
vi a;

int firstGreater(int x){
    int idx = -1;

    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(a[mid] >= x){
            idx = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    return idx;
}

int lastLess(int x){
    int idx = -1;

    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(x >= a[mid]){
            idx = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return idx;
}

void solve(){
    cin >> n;
    a.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    cin >> q;
    while(q--){
        int x; cin >> x;
//        int tmp1 = firstGreater(x);
        int tmp2 = lastLess(x);
        if(tmp2 == -1) cout << 0 << endl;
        else cout << tmp2 << endl;
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
