#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m,k,x[MM],y[MM],z[MM];
struct Node{int x,y,z;} a[MM];

void coordcompress()
{
    vector<int> dx,dy;
    dy.push_back(m);
    for(int i = 1;i <= k;i++) {
        dx.push_back(x[i]);
        dy.push_back(y[i]);
    }
    sort(dx.begin(),dx.end());
    sort(dy.begin(),dy.end());
    dx.erase(unique(dx.begin(),dx.end()),dx.end());
    dy.erase(unique(dy.begin(),dy.end()),dy.end());
    for(int i = 1;i <= k;i++) {
        x[i] = lower_bound(dx.begin(),dx.end(),x[i]) - dx.begin() + 1;
        y[i] = lower_bound(dy.begin(),dy.end(),y[i]) - dy.begin() + 1;
        a[i] = {x[i],y[i],z[i]};
    }
    m = lower_bound(dy.begin(),dy.end(),m) - dy.begin() + 1;
    sort(a+1,a+k+1,[] (Node a,Node b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });
}


ll st[MM * 4];
void update(int id,int l,int r,int u,int v,ll val)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id] = max(st[id],val);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) cin >> x[i] >> y[i] >> z[i];
    coordcompress();
    ll res = 0;
    for(int i = 1;i <= k;i++) {
        ll val = get(1,1,m,1,a[i].y);
        // cout << a[i].y << ' ' << a[i].z << ' ' << val << '\n';
        res = max(res,val + a[i].z);
        update(1,1,m,a[i].y,a[i].y,val + a[i].z);
    }
    cout << res;
    // for(int i = 1;i <= k;i++) cout << a[i].y << ' ' << a[i].z << '\n';
    return 0;
}