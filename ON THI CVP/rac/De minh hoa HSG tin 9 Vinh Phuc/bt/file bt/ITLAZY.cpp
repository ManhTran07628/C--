#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],st[N*4],lazy[N*4];

void build(ll id,ll l,ll r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = max(st[id*2],st[id*2+1]);
}

void update(ll id,ll l,ll r,ll x,ll y,ll val)
{
    if(l > y || r < x) return;
    if(x <= l && r <= y) {
        lazy[id] += val;
        st[id] += val;
        return;
    }
    st[id*2] += lazy[id];
    st[id*2+1] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    ll mid = (l+r)/2;
    update(id*2,l,mid,x,y,val);
    update(id*2+1,mid+1,r,x,y,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll x,ll y)
{
    if(l > y || r < x) return -1e18;
    if(x <= l && r <= y) return st[id];
    st[id*2] += lazy[id];
    st[id*2+1] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    ll mid = (l+r) / 2;
    return max(get(id*2,l,mid,x,y),get(id*2+1,mid+1,r,x,y));
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1,1,n);
    ll q;
    cin >> q;
    while(q--) {
        ll z;
        cin >> z;
        if(z == 1) {
            ll x,y,val;
            cin >> x >> y >> val;
            update(1,1,n,x,y,val);
        }
        else {
            ll l,r;
            cin >> l >> r;
            cout << get(1,1,n,l,r) << '\n';
        }
    }

    return 0;
}