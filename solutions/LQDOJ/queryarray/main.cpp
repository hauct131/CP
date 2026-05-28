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
        vi tree, lazy;
        int n;
        int neutral = 0;
        int mergeNode(int left, int right){
            return left + right;
        }

        void build(int id, int l, int r, const vi &a){
            if(l == r){
                tree[id] = a[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(id * 2, l, mid, a);
            build(id * 2 + 1, mid + 1, r, a);
            tree[id] = mergeNode(tree[id * 2], tree[id * 2 + 1]);
        }

        void applyNode(int id, int l, int r, int v){
            tree[id] += (r - l + 1) * v;
            lazy[id] += v;
        }

        void push(int id, int l, int r){
            if(lazy[id] == 0) return;

            int mid = (l + r) >> 1;
            applyNode(id * 2, l, mid, lazy[id]);
            applyNode(id * 2 + 1, mid + 1, r, lazy[id]);

            lazy[id] = 0;
        }

        void update1(int id, int l, int r, int u, int x){
            if(l == r){
                tree[id] = x;
                return;
            }
            int mid = (l + r) >> 1;
            if(u <= mid) update1(id * 2, l, mid, u, x);
            else update1(id * 2 + 1, mid + 1, r, u, x);
            tree[id] = mergeNode(tree[id*2], tree[id * 2 + 1]);
        }

        void update(int id, int l, int r, int u, int v, int x){
            if(v < l || r < u){
                return;
            }
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
            if(v < l || r < u){
                return neutral;
            }
            if(u <= l && r <= v){
                return tree[id];
            }
            push(id, l, r);
            int mid = (l + r) >> 1;
            int t1 = get(id * 2, l, mid, u, v);
            int t2 = get(id * 2 + 1, mid + 1, r, u, v);
            return mergeNode(t1, t2);
        }
    public:
        SegTree(){}
        SegTree(int _n){
            n = _n;
            tree.resize(4 * n + 5, 0);
            lazy.resize(4 * n + 5, 0);
        }
        void update(int l, int r, int v){
            update(1, 1, n, l, r, v);
        }
        int get(int l, int r){
            return get(1, 1, n, l, r);
        }
        void build(const vi &a){
            build(1, 1, n, a);
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
