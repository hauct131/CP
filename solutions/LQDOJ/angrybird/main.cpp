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

vi a;
int n, k;

bool check(int R){
    int tmp = 0;
    int Max = -1e18;
    for(int i = 1; i <= n; i++){
        if(a[i] > Max){
            tmp++;
            Max = a[i] + 2*R;
        }
        if(tmp > k) return false;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    a.assign(n + 1, 0);
    for(int i = 1 ; i<= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int l = 0, r = 1e15;
    int ans = 0;
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
