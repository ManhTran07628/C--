#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,a[MM],dpL[MM],dpR[MM];

int st[MM*4];

void update(int id,int l,int r,int pos)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id]++;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void solve()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
        // cout << a[i] << ' ';
    }
    // cout << '\n';

    int lim = v.size();
    for(int i = 1;i <= n;i++) {
        dpL[i] = get(1,1,lim,a[i]+1,lim);
        update(1,1,lim,a[i]);
    }
    memset(st,0,sizeof(st));
    for(int i = n;i >= 1;i--) {
        dpR[i] = get(1,1,lim,a[i]+1,lim);
        update(1,1,lim,a[i]);
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += min(dpL[i],dpR[i]);
        // cout << dpL[i] << ' ' << dpR[i] << '\n';
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    solve();

    return 0;
}