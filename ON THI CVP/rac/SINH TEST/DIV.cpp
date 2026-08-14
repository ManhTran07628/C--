#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int MOD = 1e9 + 7;
int n,a[MM],mp[MM],compress[MM],q;
vector<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void sieve()
{   
    for(int i = 2;i * i < MM;i++)
        if(mp[i] == 0)
            for(int j = i * i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;
    
    for(int i = 2;i < MM;i++)
        if(mp[i] == 0) 
            mp[i] = i;

}

struct Node
{
    pii cntdiv[27];
    // fi - phantu    se - so phan tu
} st[MM * 4],f;

Node merge(Node a,Node b)
{
    Node res = {};
    for(int i = 0;i < 25;i++)
        res.cntdiv[i] = {a.cntdiv[i].fi,a.cntdiv[i].se + b.cntdiv[i].se};
    return res;
}

void factorize(int nums, Node &a)
{
    while(nums > 1) {
        int p = mp[nums];
        a.cntdiv[ compress[p] ].fi = p;
        while(nums % p == 0) {
            a.cntdiv[ compress[p] ].se++;
            nums /= p;
        }
    }
}

void build(int id,int l,int r)
{
    if(l == r) {
        factorize(a[l],st[id]);
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        // delete
        for(int i = 0;i < 26;i++) st[id].cntdiv[i].se = 0;
        // add
        factorize(val,st[id]);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return f;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    for(int i = 0;i < primes.size();i++) 
        compress[ primes[i] ] = i;

    for(int i = 1;i < MM * 4;i++)
        for(auto p : primes) {
            st[i].cntdiv[ compress[p] ].fi = p;
            f.cntdiv[ compress[p] ].fi = p;
        }

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while(q--) {
        int type; cin >> type;
        if(type == 0) {
            int i,x; cin >> i >> x;
            update(1,1,n,i,x);
        }
        else {
            int l,r; cin >> l >> r;
            ll res = 1;
            Node P = get(1,1,n,l,r);
            for(int i = 0;i < 25;i++) {
                res *= 1ll * (P.cntdiv[i].se + 1);
                res %= MOD;
            }
            cout << res << '\n';
        }
    }
    return 0;
}