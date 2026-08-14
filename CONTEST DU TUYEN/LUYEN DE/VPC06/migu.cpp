#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e5 + 7;
ll t,a[MM],n;

namespace subtask1
{
    void solve()
    {
        ll res = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++) {
                if(a[i] * a[j] == i + j) {
                    res++;
                }
            }
        cout << res << '\n';
    }
}

namespace subtask2
{
    int pos[MM];

    void solve()
    {
        for(int i = 1;i <= n;i++) pos[ a[i] ] = i;
        ll res = 0;
        for(ll i = 1;i * i <= 2 * n;i++) {
            for(ll j = i + 1;j <= n;j++) {
                if(i * j > n * 2) break;
                if(pos[i] + pos[j] == i * j) {
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "MIGU"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        if(n <= 1000) subtask1::solve();
        else subtask2::solve();
    }
    return 0;
}