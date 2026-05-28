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
vi a;

bool check(int x){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i] / x;
    }
    return sum >= k;
}

void solve(){
    int ans = -1;

    cin >> n >> k;
    a.resize(n + 1, 0);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum / k < 1){
        cout << 0 << endl;
        return;
    }
    else{
        int l = 1, r = 1e18;

        while(l <= r){
            int mid = (l + r) >> 1;

            if(check(mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    cout << (ans == -1 ? 0 : ans) << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
