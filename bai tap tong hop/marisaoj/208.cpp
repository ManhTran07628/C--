#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,a[MM];

void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

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
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll cnt = get(1,1,n,a[i]+1,n);
        update(1,1,n,a[i]);
        ans += cnt;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}