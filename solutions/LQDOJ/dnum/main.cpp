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

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MAXN = 2*1e6;
int a, b;
int prime[MAXN + 5];

void eratosthenes()
{
    for(int i = 0; i <= MAXN; i++) prime[i] = i;
    for(int i = 2; i*i <= MAXN; i++)
    {
        if(prime[i] == i)
        {
            for(int j = i; j*i <= MAXN; j++)
            {
                prime[i*j] = i;
            }
        }
    }
}

int uocN(int n)
{
    int sum = 0;
    while(n > 1)
    {
        sum++;
        n /= prime[n];
    }
    return sum;
}

void solve()
{
    eratosthenes();
    while(cin >> a >> b)
    {
        int c = __gcd(a, b);
        int d = uocN(a/c);
        int e = uocN(b/c);
        cout << d + e << endl;
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
