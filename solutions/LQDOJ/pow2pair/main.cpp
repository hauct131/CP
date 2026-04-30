#include <bits/stdc++.h>
using namespace std;

#define FILE_IO

#define ll long long
#define int long long

const int maxn = 1e5+15;
int n;
vector<int> a;
int freq[2005];
int cnt = 0;
void solve_TC1() {
//    unordered_map<int, int> pow2;
//    for(int i = 0; i <= 36; i++){
//        int val = pow(2, i);
//        pow2[val] = i;
//    }
//    for(pair x : pow2) cout << x.first << " " << x.second << endl;
    int cnt = 0;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int x = a[i] + a[j];
            if((x & (x-1)) == 0){
                cnt++;
//                cout << a[i] << " " << a[j] << endl;
            }
        }
    }
    cout << cnt << endl;
}

void solve_TC2(){
    for(int i = 1; i <= 1005; i++){
        for(int j = i; j <= 1005; j++){
            if(((i+j)&(i+j-1)) == 0){
                if(i != j) cnt += freq[i]*freq[j];
                else{
                    cnt += freq[i]*(freq[i]-1)/2;
                }
            }
        }
    }
    cout << cnt;
}

void solve_TC3(){
    cnt = 0;
    map<int ,int> mp;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 33; j++){
            int need = (1ll<<j) - a[i];
            if(need < 0) continue;
            if(mp.count(need) > 0){
                cnt += mp[need];
            }
        }
        mp[a[i]]++;
    }
    cout << cnt;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef FILE_IO
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    a.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] <= 2004) freq[a[i]]++;
    }

//    if(n <= 1000) solve_TC1();
//    else
//        solve_TC2();
    solve_TC3();

    return 0;
}
