#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e5+7;
int n,m,h[MM],st[MM*4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = h[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = max(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] -= val;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int k)
{
    if(st[id] < k) return 0;
    if(l == r) return l;
    int mid = (l+r)/2;
    if(st[id*2] >= k) return get(id*2,l,mid,k);
    return get(id*2+1,mid+1,r,k);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    build(1,1,n);
    while(m--) {
        int r;
        cin >> r;
        int ans = get(1,1,n,r);
        cout << ans << ' ';
        update(1,1,n,ans,r);
    }
    return 0;
}