#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int dp[MM],st[MM*4],n,a[MM],d[MM],ans = 0;

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = max(st[id],val);
        // cout << st[id] << ' ' << pos << '\n';
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> ds;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ds.push_back(a[i]);
    }
    sort(ds.begin(),ds.end());
    ds.erase(unique(ds.begin(),ds.end()),ds.end());
    for(int i = 1;i <= n;i++) {
        d[i] = lower_bound(ds.begin(),ds.end(),a[i])-ds.begin()+1;
    }
    for(int i = 1;i <= n;i++) {
        dp[i] = get(1,1,n,1,d[i]-1);
        update(1,1,n,d[i],dp[i]+1);
        ans = max(ans,dp[i]+1);
    }
    cout << ans;
    return 0;
}