#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],lazy[N*4],st[N*4];

void update(int id,int l,int r,int u,int v,int d)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id] += d;
        lazy[id] += d;
        return;
    }
    st[id*2] += lazy[id];
    st[id*2+1] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,d);
    update(id*2+1,mid+1,r,u,v,d);
    st[id] = max(st[id*2],st[id*2+1]);

}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return -1e18 ;
    if(u <= l && r <= v) return st[id];
    st[id*2] += lazy[id];
    st[id*2+1] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,m;
    cin >> n >> m;
    while(m--) {
        int x,u,v,d;
        cin >> x >> u >> v;
        if(x == 0) {
            cin >> d;
            update(1,1,n,u,v,d);
        }
        else cout << get(1,1,n,u,v) << '\n';
    }
    return 0;
}