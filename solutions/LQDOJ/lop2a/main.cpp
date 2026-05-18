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

int a1, b1, a2, b2;

void solve1(){
    if(a1 * b2 == a2 * b1){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

signed main()
{
    init();
    cin >> a1 >> b1 >> a2 >> b2;
//    solve1();
    int x = __gcd(a1, b1);
    int y = __gcd(a2, b2);
    a1 /= x;
    a2 /= y;
    b1 /= x;
    b2 /= y;
    if ((a1 == a2 && b1 == b2) || (a1 == b2 && b1 == a2))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
