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

int n, k;
vi cnt;

bool check(int t){
    int thieu = 0;
    int du = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] < t){
            du += (t-cnt[i])/2;
        }
        else{
            thieu += (cnt[i] - t);
        }
    }
    return du >= thieu;
}

void solve(){
    cin >> n >> k;
    cnt.assign(n + 1, 0);
    for(int i = 1; i <= k; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    int l = 1, r = 2*k;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << endl;
}

signed main()
{
    init();
    int t; cin >> t; while(t--)
    solve();

    return 0;
}
