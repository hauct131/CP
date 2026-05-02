#include <bits/stdc++.h>
using namespace std;

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> void print_v(vector<T> &v) {
    cout << "{";
    for (auto x : v) cout << x << ",";
    cout << "\b}\n";
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int n,k;
string s;
int ans;

int max_len(string a){
    int maxlen = 0;
    int suffix = 0;
    for(int i = 0; i < (int)a.size(); i++){
        if(i > 0 && a[i] == a[i-1]){
            suffix++;
        }
        else suffix = 1;
        maxlen = max(maxlen, suffix);
    }
    return maxlen;
}

string del_string(const string& s, char c) {
    string res;
    for (char ch : s) {
        if (ch != c) res += ch;
    }
    return res;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    int res = max_len(s);

    if(k == 25){
        map<char, int> mp;
        for(auto x : s){
            mp[x]++;
            res = max(res, mp[x]);
        }
        cout << res << endl;
        return;
    }
    for (char i = 'a'; i <= 'z'; i++) {
        res = max(res, max_len(del_string(s, i)));
    }
    cout << res << endl;
}

void Try(int idx, vector<bool> del, int remove){
    if(idx > n) return;
    if(remove > k) return;

    if(idx == (int)s.size()){
        string res = "";
        for(char c : s){
            if(!del[c - 'a']){
                res += c;
            }
        }
        if(!res.empty())
            ans = max(ans, max_len(res));
        return;
    }

    Try(idx + 1, del, remove);

    int id = s[idx] - 'a';
    if(remove < k && !del[id]){
        del[id] = 1;
        Try(idx + 1, del, remove + 1);
    }
}

void tc3(){ //n <= 20, k <= 25
    cin >> n >> k;
    cin >> s;
    ans = 0;
    vector<bool> del(26, false);
    Try(0, del, 0);
    cout << ans << endl;
}

int num_distinct = 0;
int cnt[26];
void add(char c){
    num_distinct += (++cnt[c-'a'] == 1);
}

void del(char c){
    num_distinct -= (--cnt[c-'a'] == 0);
}

int main() {
    init();
    cin >> n >> k >> s;
//    if (k == 1) {
//        int res = max_len(s);
//        for (char c = 'a'; c <= 'z'; c++)
//            res = max(res, max_len(del_string(s, c)));
//        cout << res << '\n';
//    }
//    else if (k == 25) {
//        vector<int> freq(26, 0);
//        int res = 0;
//        for (char c : s) {
//            freq[c - 'a']++;
//            res = max(res, freq[c - 'a']);
//        }
//        cout << res << '\n';
//    }
//    else if (n <= 20) {
//        ans = 0;
//        vector<bool> del(26, false);
//        Try(0, del, 0);
//        cout << ans << '\n';
//    }
//    else {
    ans = 0;
    for(int r = 0, l = 0; r < n; r++)
    {
        add(s[r]);
        while(l < r && num_distinct > k + 1)
        {
            del(s[l]);
            l++;
        }
        int tmp = 0;
        for(int i = 0; i < 26; i++)
        {
            tmp = max(tmp, cnt[i]);
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
//    }
    return 0;
}
