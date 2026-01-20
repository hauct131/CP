/*
 * PROBLEM: pow2pair
 * LINK: https://lqdoj.edu.vn/problem/pow2pair
 * -------------------------
 /** \brief

 Tom tat de: Cho mot day gom n phan tu ai <= 10^9. dem so cap ai, aj ma
 tong cua chung la luy thua cua 2

 subtask 1: duyet O(n^2)
 subtask 2: duyet tren gia tri ai O(n^2)
 subtask 3: nhan xet chi co khoang 2^32 >= 2*10^9 => duyet theo so mu cua 2
 voi moi x thi ta se xet xem doan truoc no co ton tai mot gia tri 2^i - x nao khong
 neu co thi se cong vao ket qua
 DPT O(n * 32 * log n)
  *
  */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define F first
#define S second
#define endl "\n"
const int MAXN = 10e5+5;
int n;
int a[MAXN];
map<int, int> mp;

bool check(int x, int y)
{
    int sum = x + y;
    return ((sum & (sum - 1)) == 0);
}

int sub1()
{
    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int sum = a[i] + a[j];
            if((sum & (sum - 1)) == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int sub2()
{
    int cnt = 0;

    for(auto x : mp)
    {
        for(auto y : mp)
        {
            if(check(x.F, y.F))
            {
                if(x.F > y.F) continue;

                if(x.F == y.F)
                {
                    cnt += x.S*(x.S - 1)/2;
                }
                else if (x.F < y.F)
                {
                    cnt += x.S * y.S;
                }
            }
        }
    }

    return cnt;
}

void solve()
{
    int res = 0;
    cin >> n;
    int x;
    for(int j = 1; j <= n; j++)
    {
        cin >> x;
        for(int i = 0; i <= 32; i++){
            if(mp.find((1 << i) - x) != mp.end()){
                res += mp[(1 << i) - x];
            }
        }
        mp[x]++;

    }

    cout << res << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("/home/hao/Olympic/input.txt", "r"))
    {
        freopen("/home/hao/Olympic/input.txt", "r", stdin);
        freopen("/home/hao/Olympic/output.txt", "w", stdout);
    }

    solve();

    return 0;
}


