#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll tv[N*4],a[N];

void build(ll v,ll l,ll r)
{
    if(l == r) {
        tv[v] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * v,l,mid);
    build(2 * v + 1,mid + 1,r);
    tv[v] = tv[2 * v] + tv[2 * v + 1];
}

void update(ll v,ll l,ll r,ll pos,ll val)
{
    if(l == r) {
        tv[v] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if(pos <= mid) update(2 * v,l,mid,pos,val);
    else update(2 * v + 1,mid + 1,r,pos,val);
    tv[v] = tv[2 * v] + tv[2 * v + 1];
}

ll get(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l > r) return 0;
    if(tl == l && tr == r) return tv[v];
    ll mid = (tl+tr)/2;
    ll x1 = get(2 * v,tl,mid,l,min(mid,r));
    ll x2 = get(2 * v + 1,mid+1,tr,max(mid + 1,l),r);
    return x1 + x2;
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
    int n,q;
    cin >> n >> q;
    while(q--) {
        ll u,i,x;
        cin >> u >> i >> x;
        if(u == 1) {
            update(1,1,n,i,x);
        }
        else {
            cout << get(1,1,n,i,x) << '\n';
        }
    }
    return 0;
}
