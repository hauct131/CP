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

bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i*i <= n; i+= 6){
        if(n % (i) == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int n;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(isPrime(i)) cout << i << "\n";
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
