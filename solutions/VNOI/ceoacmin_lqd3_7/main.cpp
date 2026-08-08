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

const int MAXN = 5e4+5;

int n, k;
int a[MAXN];

bool check(int R){
    int maxDes = LLONG_MIN;
    int birds = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > maxDes){
            maxDes = a[i] + 2 * R;
            birds++;
            if(birds > k) return false;
        }
    }
    return true;
}
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0, r = LLONG_MAX;
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

