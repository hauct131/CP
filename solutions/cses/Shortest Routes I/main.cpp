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

const int MAXN = 1e5+2;
const int INF = (1ll << 62);
int n, m;
vpii a[MAXN];
vi d;

void dijkstra(int s){
    priority_queue<pii, vpii, greater<pii>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        auto [du, u] = pq.top();
        pq.pop();
        if(du != d[u]) continue;
        for(auto [v, w] : a[u]){
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    d.assign(n + 1, INF);
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
    }
//    for(int i = 1; i <= n; i++){
//        for(auto x : a[i]){
//            cout << i << " " << x.F << " " << x.S << endl;
//        }
//    }
    dijkstra(1);
    for(int i = 1; i <= n; i++) cout << d[i] << " ";
}

signed main()
{
    init();

    solve();

    return 0;
}
