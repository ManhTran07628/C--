#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int MOD = 1e9 + 7;        
int n,q;
ll ps[MM],val[MM],f[MM];

namespace subtask12
{
    void solve()
    {
        cin >> n >> q;
        while(q--) {
            char type;
            int x,y; cin >> type >> x >> y;
            if(type == 'D') {
                for(int i = x;i <= y;i++) val[i]++;
                for(int i = 1;i <= n;i++) {
                    ps[i] = ps[i - 1] + f[ val[i] ];
                    ps[i] %= MOD;
                }
            }
            else {
                ll res = (ps[y] - ps[x - 1] % MOD + MOD) % MOD;
                cout << res << '\n'; 
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "FIBSEQ"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    f[0] = 0;
    f[1] = 1;
    for(int i = 2;i < MM;i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    subtask12::solve();
    return 0;
}