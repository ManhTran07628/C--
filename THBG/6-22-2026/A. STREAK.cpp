#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 5e5 + 7;
int n,k;
string s;

struct Node
{
    ll prefix,suffix,sum,Max;
} st[MM * 4];

Node Merge(Node a,Node b)
{
    ll sum = a.sum + b.sum;
    ll prefix = max(a.prefix,a.sum + b.prefix);
    ll suffix = max(b.suffix,a.suffix + b.sum);
    ll Max = max({a.suffix + b.prefix,a.Max,b.Max});
    return {prefix,suffix,sum,Max};
}

void build(int id,int l,int r)
{
    if(l == r) {
        ll val = (s[l] == '0' ? 1 : -1e9);
        st[id] = {max(0ll,val),max(0ll,val),val,max(0ll,val)};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        if(s[l] == '0') s[l] = '1';
        else s[l] = '0';
        ll val = (s[l] == '0' ? 1 : -1e9);
        st[id] = {max(0ll,val),max(0ll,val),val,max(0ll,val)};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id)
{
    return st[id];
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
    cin >> n >> k;
    cin >> s; s = ' ' + s;
    build(1,1,n);
    // cout << get(1).Max;
    while(k--) {
        int k; cin >> k;
        update(1,1,n,k);
        cout << get(1).Max << '\n';
    }
    return 0;
}