#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 3e5+7;
ll n,k;
ll a[MM],ps[MM],suffix[MM];
ll ans = 0;

void solve(ll a[])
{
    int maxl = n-k+1;
    memset(ps,0,sizeof(ps));
    fill(suffix+1,suffix+n+1,oo);
    suffix[n+1] = oo;
    for(int i = 1;i <= n;i++) 
        ps[i] = ps[i-1] + a[i];
    for(int i = n;i >= 1;i--) 
        suffix[i] = min(suffix[i+1],a[i]);
    if(k == 2) {
        ans = max(ans,ps[n-1] - (ps[n]-ps[n-1]));
        return;
    }
    for(int i = 1;i <= n;i++) {
        int j = max(1,i-maxl+1);
        ll min_val = suffix[i+1];
        ans = max(ans,(ps[i]-ps[j-1])-min_val);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    solve(a);
    reverse(a+1,a+n+1);
    solve(a);
    cout << ans;
    return 0;
}