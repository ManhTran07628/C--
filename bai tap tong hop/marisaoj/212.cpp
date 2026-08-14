#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int MOD = 1e9 + 7;
int n,q;
ll a[MM],st[MM * 4],cnt[MM * 4],b[MM * 4];

void fix(int id,int l,int r)
{
    if(!cnt[id] && !b[id]) return;
    ll p1 = ( (r - l) * (r - l + 1) / 2 % MOD + l * (r - l + 1) % MOD ) * cnt[id] % MOD;
    ll p2 = ( b[id] * (r - l + 1) % MOD + MOD ) % MOD;
    st[id] = (st[id] % MOD + p1 % MOD + p2 % MOD) % MOD;
    if(l != r) {
        cnt[id*2] += cnt[id];
        cnt[id*2+1] += cnt[id];
        b[id*2] += b[id];
        b[id*2+1] += b[id];
    }
    cnt[id] = 0;
    b[id] = 0;
}

void update(int id,int l,int r,int u,int v,ll val1,ll val2)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        cnt[id] += val1; cnt[id] = (cnt[id] + MOD) % MOD;
        b[id] += val2; b[id] = (b[id] + MOD) % MOD;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val1,val2);
    update(id*2+1,mid+1,r,u,v,val1,val2);
    st[id] = st[id*2] + st[id*2+1]; st[id] %= MOD;
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return ( get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v) ) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            ll l,r,x,y;
            cin >> l >> r >> x >> y;
            ll val2 = (MOD + -(l * x - y)) % MOD;
            update(1,1,n,l,r,x, val2 );
        }
        else {
            int l,r; cin >> l >> r;
            cout << get(1,1,n,l,r) << '\n';
        }
    }
    return 0;
}