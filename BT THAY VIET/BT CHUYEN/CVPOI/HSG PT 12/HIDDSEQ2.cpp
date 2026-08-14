#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 4e5 + 7;
const int lim = 1e6;
int n,q,st[MM * 4],lazy[MM * 4],last_conf[MM],L[MM],nxt[MM];
int up[MM][19];
pii seg[MM];

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] = max(st[id],lazy[id]);
    if(l != r) {
        lazy[id*2] = max(lazy[id*2],lazy[id]);
        lazy[id*2+1] = max(lazy[id*2+1],lazy[id]);
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v,int val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] = max(lazy[id],val);
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(seg[i].fi);
    for(int i = 1;i <= n;i++) v.push_back(seg[i].se);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        seg[i].fi = lower_bound(v.begin(),v.end(),seg[i].fi) - v.begin() + 1;
        seg[i].se = lower_bound(v.begin(),v.end(),seg[i].se) - v.begin() + 1;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> seg[i].fi >> seg[i].se;
    coordcompress();
    L[0] = 1;
    for(int i = 1;i <= n;i++) {
        last_conf[i] = get(1,1,lim,seg[i].fi,seg[i].se);
        update(1,1,lim,seg[i].fi,seg[i].se,i);
        L[i] = max(L[i-1],last_conf[i] + 1);
        // cout << last_conf[i] << ' ';
    }
    for(int i = 1,r = 1;i <= n;i++) {
        while(r <= n && L[r] <= i) r++;
        nxt[i] = r;
        // cout << nxt[i] << ' ';
        up[i][0] = nxt[i];
    }
    up[n+1][0] = n + 1;
    for(int j = 1;j <= 18;j++) {
        for(int i = 1;i <= n + 1;i++) 
            up[i][j] = up[ up[i][j-1] ][j-1];
    }

    cin >> q;
    for(int i = 1;i <= q;i++) {
        int a,b; cin >> a >> b;
        int curr = a, ans = 0;
        for(int j = 18;j >= 0;j--)
            if(up[curr][j] <= b) {
                curr = up[curr][j];
                ans += (1 << j);
            }
        cout << ans + 1 << '\n';
    }

    return 0;
}
// lớn nhất <= đoạn [u,v]  nhỏ nhất > [u,v] 