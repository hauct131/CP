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
#define pb push_back

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n;
set<int> ans;

void check(int n)
{
    int dem = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            cout << i << endl;
            dem++;
        }
    }
}

void check1(int n)
{
    int sum = 0, cnt = 0;
    for(int x = 1; x*x <= n; x++)
    {
        if(n % x == 0)
        {
            if(x*x != n)
            {
                sum += x + n/x;
                cnt += 2;
            }
            else
            {
                sum += x;
                cnt += 1;
            }
        }
    }
    cout << sum << endl;
}

void solve()
{
    cin >> n;
    check1(n);

}

signed main()
{
    init();

    solve();

    return 0;
}
