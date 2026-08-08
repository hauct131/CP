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

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MAXN = 2e5+5;
int n;
pair<int, int> a[MAXN];

bool check(int D){
    int minY = LLONG_MAX;
    int maxY = LLONG_MIN;
    int j = 1;

    for(int i = 2; i <= n; i++){
        while(j < i && a[j].F <= a[i].F - D){
            minY = min(minY, a[j].S);
            maxY = max(maxY, a[j].S);
            j++;
        }
        if(minY != LLONG_MAX && minY <= a[i].S - D){
            return true;
        }
        if(maxY != LLONG_MIN && maxY >= a[i].S + D){
            return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
    sort(a + 1, a + 1 + n);
    int ans = LLONG_MIN;
    int l = 0, r = LLONG_MAX;
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
