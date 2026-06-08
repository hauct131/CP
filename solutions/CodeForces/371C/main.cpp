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

string s;
vi a(4, 0);
vi b(4, 0);
int r = 0;
int needB, needS, needC;

bool check(int x){
    int tmp1 = needB * x;
    int tmp2 = needS * x;
    int tmp3 = needC * x;

    int buyB = max(1ll*0, tmp1 - a[1]);
    int buyS = max(1ll*0, tmp2 - a[2]);
    int buyC = max(1ll*0, tmp3 - a[3]);

    int cost = buyB*b[1] + buyS*b[2] + buyC*b[3];
    return cost <= r;
}

void solve(){
    needB = needC = needS = 0;
    cin >> s;
    for(char c : s){
        if(c == 'B') needB++;
        else if(c == 'S') needS++;
        else needC++;
    }
    cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3] >> r;

    int l = 0, r = 1e15;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
