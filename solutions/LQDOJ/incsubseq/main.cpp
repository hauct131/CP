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
const int INF = 1e10;
int n;
int a[maxn];
void solve(){
    cin >> n;
//    cout << INF << endl;
    int A, B;
    A = B = INF;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(A > B) swap(A, B);
        if(x <= A){
            A = x;
        }
        else if(x > B){
            ans++;
            A = x;
        }
        else{
            B = x;
        }
    }
    cout << ans << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
