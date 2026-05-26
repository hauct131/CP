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

const int INF = 1e9;

class SegTree{
private:
    int n;
    vector<int> tree;

    void build(const vector<int>& a, int id, int l, int r){
        if(l == r){
            tree[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, id*2, l, mid);
        build(a, id*2 + 1, mid + 1, r);
        tree[id] = max(tree[id*2], tree[id*2+1]);
    }

    void update(int id, int l, int r, int idx, int val){
        if(l == r){
            tree[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid){
            update(id * 2, l, mid, idx, val);
        }
        else{
            update(id * 2 + 1, mid + 1, r, idx, val);
        }
        tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
    }

    int query(int id, int l, int r, int u, int v){
        if(v < l || r < u) return -INF;
        if(u <= l && r <= v) return tree[id];
        int mid = (l + r) >> 1;
        int t1 = query(id * 2, l, mid, u, v);
        int t2 = query(id * 2 + 1, mid + 1, r, u, v);
        return max(t1, t2);
    }
public:
    SegTree(const vector<int>& a, int N){
        n = N;
        tree.resize(n * 4 + 5, 0);
        build(a, 1, 1, n);
    }

    void set(int idx, int val){
        update(1, 1, n, idx, val);
    }

    int get(int l, int r){
        return query(1, 1, n, l, r);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    SegTree st(a, n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
        else{
            int l, r; cin >> l >> r;
            cout << st.get(l, r) << endl;
        }
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
