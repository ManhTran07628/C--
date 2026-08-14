#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 19 + 7;
ll n,t,a[MM];
ll dp[MM][MM][MM][MM];

ll calc(int id,ll vmin1,ll vmin2,ll vmax)
{
    if(id == n) return vmin1 + vmin2 > vmax;
    ll memo = dp[id][vmin1][vmin2][vmax];
    if(memo != -1) return memo;

    memo = 0;
    for(ll i = 1;i <= n;i++) {
        int new_vmin1, new_vmin2, new_vmax = max(vmax,i);
        if(i < vmin1) {
            new_vmin2 = vmin1;
            new_vmin1 = i;
        }
        else {
            new_vmin2 = min(vmin2,i);
            new_vmin1 = vmin1;
        }

        memo += calc(id+1,new_vmin1,new_vmin2,new_vmax);
    }

    dp[id][vmin1][vmin2][vmax] = memo;
    return memo;
}

void find_arr(int id,ll vmin1,ll vmin2,ll vmax,ll sum)
{
    if(id == n) return;

    for(ll i = 1;i <= n;i++) {
        int new_vmin1, new_vmin2, new_vmax = max(vmax,i);
        if(i < vmin1) {
            new_vmin2 = vmin1;
            new_vmin1 = i;
        }
        else {
            new_vmin2 = min(vmin2,i);
            new_vmin1 = vmin1;
        }

        if(calc(id+1,new_vmin1,new_vmin2,new_vmax) < sum) {
            sum -= calc(id+1,new_vmin1,new_vmin2,new_vmax);
        }
        else {
            cout << i << ' ';
            find_arr(id+1,new_vmin1,new_vmin2,new_vmax,sum);
            break;
        }
    }
}


ll res_pos = 0;
void find_pos(int id,ll vmin1,ll vmin2,ll vmax)
{
    if(id == n) return;

    for(ll i = 1;i <= a[id];i++) {
        ll new_vmin1, new_vmin2, new_vmax = max(vmax,i);
        if(i < vmin1) {
            new_vmin2 = vmin1;
            new_vmin1 = i;
        }
        else {
            new_vmin2 = min(vmin2,i);
            new_vmin1 = vmin1;
        }

        
        if(i != a[id]) res_pos += calc(id+1,new_vmin1,new_vmin2,new_vmax);
        else {
            find_pos(id+1,new_vmin1,new_vmin2,new_vmax);
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> t;
    for(int i = 0;i < n;i++) {
        cin >> a[i];      
    }

    memset(dp,-1,sizeof(dp));
    cout << calc(0,n+1,n+1,0) << '\n';
    find_arr(0,n+1,n+1,0,t);
    cout << '\n';
    find_pos(0,n+1,n+1,0);
    cout << res_pos + 1;

    return 0;
}