#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

#define endl "\n"

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

const int maxn = 1e5+5;
int n, k;
int a[maxn];
int f[maxn];
int g[maxn];
void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    int j = 1;
    for(int i = 1; i <= n; i++){
        while(j <= n && a[j] - a[i] <= k) j++;
        f[i] = j - i;
    }
    j = n;
    for(int i = n; i >= 1; i--){
        while(j >= 1 && a[i] - a[j] <= k) j--;
        g[i] = i - j;
    }
    for(int i = n - 1; i >= 1; i--){
        f[i] = max(f[i], f[i+1]);
    }
    for(int i = 2; i <= n; i++){
        g[i] = max(g[i], g[i-1]);
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
        ans = max(ans, f[i] + g[i-1]);
    }
    cout << ans << endl;
}

signed main()
{
    init();
    auto start = clock();
    solve();
    auto End = clock();
    cerr << start - End << endl;
    return 0;
}
