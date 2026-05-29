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

vii pos;

bool cmp(int x, int y){
    int cnt = 0;
    for(int i = 1; i <= 5; i++){
        if(pos[i][x] < pos[i][y]) cnt++;
    }
    return cnt >= 3;
}

void solve(){
    int n;
    cin >> n;

    pos.resize(6, vi(n + 1, 0));

    for(int i = 1; i <= 5; i++){
        for(int j = 1;j <= n; j++){
            int x; cin >> x;
            pos[i][x] = j;
        }
    }

    vi ans(n + 1, 0);
    for(int i = 1; i <= n; i++) ans[i] = i;
    sort(ans.begin() + 1, ans.end(), cmp);

    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
//    for(int i = 1; i <= 5; i++){
//        for(int j = 1;j <= n; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
}

signed main()
{
    init();

    solve();

    return 0;
}
