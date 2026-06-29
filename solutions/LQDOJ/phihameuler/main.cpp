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

const int MAXN = 5e6+5;

int isPrime[MAXN + 5];
int phi[MAXN + 5];
void start(){
    for(int i = 1; i <= MAXN; i++){
        isPrime[i] = phi[i] = i;
    }

    for(int i = 2; i<= MAXN; i++){
        if(isPrime[i] == i){
            for(int j = i; j <= MAXN; j+=i){
                if(isPrime[j] == j){
                    isPrime[j] = i;
                }

                phi[j] -= phi[j]/i;
            }
        }
    }
}

int n;

void solve(){
    start();
    cin >> n;
    vi tmp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        tmp[phi[i]]++;
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(tmp[i] > 1){
            res += (tmp[i]*(tmp[i] - 1))/2;
        }
    }
    cout << res << endl;
}

signed main()
{
    init();

    solve();

    return 0;
}
