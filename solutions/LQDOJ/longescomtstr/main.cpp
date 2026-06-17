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

string s, t;

void solve(){
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = ' ' + s;
    t = ' ' + t;
    string res;
    vii dp(n + 1, vi(m + 1, 0)); // dp[i][j] stores the length of
    //the Longest Common Subsequence (LCS)
    // of the first i characters of string s and the first j characters of string t.
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(s[i] == t[j]){
            res += s[i];
            i--; j--;
        }
        else{
            if(dp[i-1][j] >= dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
