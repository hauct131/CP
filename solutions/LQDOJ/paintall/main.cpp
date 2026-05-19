#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll

#define endl "\n"

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

const int MAXN = 100000 + 5;

int n;
vector<int> L[MAXN];
bool used[MAXN];
stack<int> s;
void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        used[i] = 0;
        L[a].push_back(i);
        L[b].push_back(i);
        if(i == a || i == b)
        {
            s.push(i);
            used[i] = 1;
        }
    }

    vector<int> ans;
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        ans.push_back(top);
        for(int x : L[top])
        {
            if(!used[x])
            {
                used[x] = 1;
                s.push(x);
            }
            else
            {
                continue;
            }
        }
    }
    if(ans.size() != n)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout << x << endl;
    }
}

signed main()
{
    init();

    solve();

    return 0;
}
