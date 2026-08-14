#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 100+7;
int t;
int fib[MM];


namespace subtask1
{
    int lim = 20;

    void solve(int n,int m) {
        int res = oo;
        for(int mask = 0;mask < (1 << lim);mask++) {
            int sum = 0,Xor = 0;
            for(int i = 0;i < lim;i++) 
                if(mask >> i & 1) {
                    sum += fib[i+1];
                    Xor ^= fib[i+1];
                }

            if(sum == m && Xor == n) {
                res = min(res,(int) __builtin_popcount(mask));
            }
        } 
        cout << (res == oo ? -1 : res) << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib[1] = fib[2] = 1;
    for(int i = 3;i <= 40;i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cin >> t;
    while(t--) {
        int m,n; cin >> m >> n;
        subtask1::solve(n,m);
    }
    return 0;
}