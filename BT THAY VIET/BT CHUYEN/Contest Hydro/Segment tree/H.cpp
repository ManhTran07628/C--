#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int n,a[MM],dp[MM][3];

namespace subtask2
{
    void solve()
    {
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            dp[i][1] = 1;
            for(int j = 1;j < i;j++) 
                if(a[j] < a[i]) {
                    dp[i][2] = (dp[i][2] + dp[j][1]);
                    dp[i][3] = (dp[i][3] + dp[j][2]);
                }
            
            ans += dp[i][3];
        }
        cout << ans;
    }
}

namespace sol
{
    ll st[4][MM * 4];

    void update(int id,int l,int r,int pos,ll val,int len)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[len][id] += val;
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,pos,val,len);
        update(id*2+1,mid+1,r,pos,val,len);
        st[len][id] = st[len][id * 2] + st[len][id * 2 + 1];
    }

    ll get(int id,int l,int r,int u,int v,int len)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[len][id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v,len) + get(id*2+1,mid+1,r,u,v,len);
    }

    void solve()
    {
        ll ans = 0,p = *max_element(a+1,a+n+1);
        for(int i = 1;i <= n;i++) {
            ll dp2 = get(1,1,p,1,a[i]-1,1);
            ll dp3 = get(1,1,p,1,a[i]-1,2);
            // cout << dp2 << ' ';
            ans += dp3;
            update(1,1,p,a[i],1,1);
            update(1,1,p,a[i],dp2,2);
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sol::solve();
    return 0;
}