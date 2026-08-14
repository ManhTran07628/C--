#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e5 + 7;
int n,t,a[MM];


namespace subtask2
{
    map<int,int> mp;
    int suf[MM],pf[MM];
    void solve()
    {
        for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + (a[i] == t);
        for(int i = 1;i <= n;i++) pf[i] = pf[i - 1] + (a[i] == t);
        int res = suf[1] - 1;


        for(int i = 1;i <= n;i++) {
            int x = t - a[i], cnt = (a[i] == t ? 0 : 1);
            for(int j = i - 1;j >= 1;j--) {
                if(a[j] + x == t) cnt++;
                res = max(res,pf[j - 1] + suf[i + 1] + cnt);
            }
            
        }
        cout << res;
    }
    
}

namespace subtask34
{
    map<ll,ll> ps,last_val;
    int suf[MM];


    void solve()
    {
        for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + (a[i] == t);

        ll res = 0, cnt_t = 0;
        for(int i = 1;i <= n;i++) {
            if(a[i] == t) cnt_t++;
            else {
                int add = cnt_t - last_val[ a[i] ];

                ps[ a[i] ] = ps[ a[i] ] - add + 1;
                if(ps[ a[i] ] <= 0) ps[ a[i] ] = 1;

                res = max(res,ps[ a[i] ] + cnt_t + suf[i + 1]);

                last_val[ a[i] ] = cnt_t;

            }
        }

        if(cnt_t == n) cout << cnt_t - 1;
        else cout << res;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "A"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> t;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // if(n <= 5000) subtask2::solve();
    // else subtask3::solve();
    subtask34::solve();
    return 0;
}