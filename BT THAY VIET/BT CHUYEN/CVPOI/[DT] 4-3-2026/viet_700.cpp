#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e3 + 7;
int n,m,k,h[MM];
int a[MM][MM],M[MM][MM],cur[MM][MM];
ll ps[MM][MM];

ll getsum(int X1,int Y1,int X2,int Y2)
{
    return ps[X2][Y2] - ps[X1 - 1][Y2] - ps[X2][Y1 - 1] + ps[X1 - 1][Y1 - 1];
}


ll st[MM * 4],lazy[MM * 4];

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] += lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void build(int id, int l, int r) {
    lazy[id] = 0;
    if (l == r) {
        st[id] = -l; 
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = min(st[id * 2], st[id * 2 + 1]);
}

void update(int id,int l,int r,int u,int v,int val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += val;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
    for(int i = 1;i <= k;i++) cin >> h[i];
    sort(h+1,h+k+1);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
            M[i][j] = a[i][j];
        }
    
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            M[i][j] = max(M[i][j],M[i-1][j]);
            cur[i][j] = lower_bound(h+1,h+k+1,M[i][j] + 1) - h;
            // cout << cur[i][j] << ' ';
        }
        // cout << '\n';
    }


    
    int res = 0;
    for(int i = 1;i <= n;i++) {
        build(1,1,k);
        for(int j1 = 1, j2 = 1;j2 <= m;j2++) {
            if(j2 <= k) {
                update(1,1,k,cur[i][j2],k,1);
            }
            else {
                update(1,1,k,cur[i][j1++],k,-1);
                update(1,1,k,cur[i][j2],k,1);
            }
            if(j2 - j1 + 1 == k) 
                if(get(1,1,k,1,k) >= 0 && getsum(i,j1,i,j2) == 0) res++;
        }
    }

    cout << res;
    // cout << ok[3][1] << ' ' << ok[3][2];
    
    return 0;
}