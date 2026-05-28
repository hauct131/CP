#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define endl "\n"
typedef vector<int> vi;
void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class SegTree{
private:
    int n;
    vi tree, lazy;

    int neutral = 0;

    int mergeNode(int left, int right){
        return left + right;
    }

    void applyNode(int id, int l, int r, int x){
        tree[id] += (r - l + 1) * x;
        lazy[id] += x;
    }

    void push(int id, int l ,int r){
        if(lazy[id] == 0) return;

        int mid = (l + r) >> 1;
        applyNode(id*2, l, mid, lazy[id]);
        applyNode(id * 2 + 1, mid + 1, r, lazy[id]);

        lazy[id] = 0;
    }

    void build(int id, int l, int r, const vi &a){
        if(l == r){
            tree[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid, a);
        build(id * 2 + 1, mid + 1, r, a);
        tree[id] = mergeNode(tree[id* 2], tree[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int v, int x){
        if(v < l || r < u) return;
        if(u <= l && r <= v){
            applyNode(id, l, r, x);
            return;
        }
        push(id, l, r);

        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, x);
        update(id * 2 + 1, mid + 1, r, u, v, x);
        tree[id] = mergeNode(tree[id*2], tree[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return neutral;
        if(u <= l && r <= v){
            return tree[id];
        }
        push(id, l, r);
        int mid = (l + r) >> 1;
        int left = get(id * 2, l, mid, u, v);
        int right = get(id * 2 + 1, mid + 1, r, u, v);
        return mergeNode(left, right);
    }

public:
    SegTree(){}
    SegTree(int n){
        this->n = n;
        tree.resize(4 * n + 5, neutral);
        lazy.resize(4 * n + 5, 0);
    }
    void build(const vi& a){
        build(1, 1, n, a);
    }

    void update(int l, int r, int x){
        update(1, 1, n, l, r, x);
    }

    int get(int l, int r){
        return get(1, 1, n, l, r);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n + 1, 0);
    SegTree st(n);

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, x; cin >> l >> r >> x;
            st.update(l, r, x);
        }
        else{
            int l, r, x; cin >> l >> r >> x;
            st.update(l, r, -x);
        }
    }
    for(int i = 1; i <= n; i++){
        cout << st.get(i, i) << " ";
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
