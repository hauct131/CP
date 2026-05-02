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

const int maxn = 2e5+5;
int n, p, h;
char a[maxn];
int res = 1e9;
void Try(int idx, int curP, int curH, int ms){
    if(idx > n){
        res = min(res, ms);
        return;
    }

    if(curP <= 0 || curH <= 0) return;

    if(a[idx] == '#'){
        Try(idx + 1, curP, curH, ms);
    }
    else if(a[idx] == 'P')
        Try(idx + 1, curP + 1, curH, ms);
    else if(a[idx] == 'H')
        Try(idx + 1, curP, curH + 1, ms);
    else{
        if(curP - 1 > 0) Try(idx + 1, curP - 1, curH, ms + 1);
        if(curH - 1 > 0) Try(idx + 1, curP, curH - 1, ms);
    }


}

void solve1() {
    Try(1, p, h, 0);
    cout << (res == 1e9 ? -1 : res) << endl;
}

int main() {
    init();
    cin >> n >> p >> h;
    for(int i = 1; i <= n; i++) cin >> a[i];

    solve1();
    return 0;
}
