#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,x[MM],y[MM];
ll C,L,R;

namespace subtask1
{
    int opt[MM];
    ll res = oo;

    ll check()
    {
        ll total_sugar = 0, total_time = 0;
        for(int i = 1;i <= n;i++) {
            if(opt[i] == 1) total_sugar += y[i];
            else {
                total_sugar += y[i];
                if(total_sugar > R || total_sugar < L) return oo;
                total_time += C + 1ll * x[i] * total_sugar;
                total_sugar = 0;
            }
        }
        return total_time;
    }    

    void Try(int i)
    {
        if(i > n) {
            res = min(res,check());
            return;
        }

        if(i < n) {
            opt[i] = 1;
            Try(i + 1);
        }
        
        opt[i] = 2;
        Try(i + 1);
    }

    void solve()
    {
        Try(1);
        cout << (res == oo ? -1 : res);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "HTH"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> C >> L >> R;
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 1;i <= n;i++) cin >> y[i];
    subtask1::solve();
    return 0;
}