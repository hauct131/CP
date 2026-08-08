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

const int MAXN = 2e5;
int n, a, b;
int arr[MAXN + 10];
int pre[MAXN + 10];

void solve(){
    cin >> n >> a >> b;
    pre[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i];
    }

    int res = LLONG_MIN;

//    for(int len = a; len <= b; len++){
//        for(int l = 1; l <= n - len + 1; l++){
//            int r = l + len - 1;
//            res = max(res, pre[r] - pre[l - 1]);
//        }
//    }

//    priority_queue<pii, vpii, greater<pii>> pq;
//    for(int r = a; r <= n; r++){
//        int left = max(0ll, r - b);
//        int right = r - a;
//
//        pq.push({pre[right], right});
//        while(!pq.empty() && pq.top().S < left){
//            pq.pop();
//        }

//    multiset<pii> ms;
//    for(int r = a; r <= n; r++){
//        int left = max(0ll, r - b);
//        int right = r - a;
//        ms.insert({pre[right], right});
//        if(left - 1 >= 0){
//            ms.erase({pre[left-1], left-1});
//        }
//        res = max(res, pre[r] - ms.begin()->F);
//    }
    deque<int> dq;
    for(int r = a; r <= n; r++){
        int left = max(0ll, r - b);
        int right = r - a;
        while(!dq.empty() && dq.front() < left){
            dq.pop_front();
        }
        while(!dq.empty() && pre[dq.back()] >= pre[right]){
            dq.pop_back();
        }
        dq.push_back(right);
        res = max(res, pre[r] - pre[dq.front()]);
    }


//        int minPre = LLONG_MAX;
//        for(int i = left; i <= right; i++){
//            minPre = min(minPre, pre[i]);
//        }
//        res = max(res, pre[r] - pq.top().F);

    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
