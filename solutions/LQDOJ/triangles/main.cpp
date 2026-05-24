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

int n;
map<int, int> mp;
vector<pair<int, int>> v; // CẦN THÊM: để truy cập index

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mp[x]++;
    }

    // CẦN THÊM: chuyển map sang vector
    for(auto x : mp){
        v.push_back(x);
    }
    int m = v.size(); // CẦN THÊM: khai báo m

    int ans = 0;

    // Giữ nguyên logic của bạn
    for(int i = 0; i < v.size(); i++){
        if(v[i].second >= 3) ans++;  // SỬA: mp[i] -> v[i].second
    }

    int j = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].second >= 2){  // SỬA: mp[i] -> v[i].second
            while(j < v.size() && v[j].first < 2*v[i].first) j++;  // SỬA: mp -> v
            ans += j - 1;
        }
    }

    for(int i = 0; i < v.size(); i++){
        int k = i + 2;
        for(int j = i + 1; j < m; j++){
            while(k < m && v[k].first < v[i].first + v[j].first) k++;  // SỬA: mp -> v
            ans += k - j - 1;
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
