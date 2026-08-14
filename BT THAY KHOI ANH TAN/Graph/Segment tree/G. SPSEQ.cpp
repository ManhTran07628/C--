#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,a[MM],st[MM*4],dpL[MM],dpR[MM],p[MM];

void update(int id,int l,int r,int u,int v,int val)
{
    if(l > v || r < u) return;
    if(l == r) {
        // cout << val << ' ' << l << '\n';
        st[id] = max(st[id],val);
        return;
    }
    int mid = (l+r)/2;
    if(u <= mid) update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
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
    vector<int> v;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        p[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    }
    
    // doan trai
    for(int i = 1;i <= n;i++) {
        dpL[i] = get(1,1,n,1,p[i]-1)+1;
        update(1,1,n,p[i],p[i],dpL[i]);
    }
    memset(st,0,sizeof(st));
    for(int i = n;i >= 1;i--) {
        dpR[i] = get(1,1,n,1,p[i]-1)+1;
        update(1,1,n,p[i],p[i],dpR[i]);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int len = min(dpL[i],dpR[i]);
        ans = max(ans,len*2-1);
    }
    cout << ans;
    return 0;
}