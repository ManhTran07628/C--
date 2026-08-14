#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e5 + 7;
int n,m;
int a[MM];

struct Node{int sum,prefix;} st[MM * 4];

Node Merge(Node a,Node b)
{
    int sum = a.sum + b.sum;
    int prefix = min(a.prefix,a.sum + b.prefix);
    return {sum,prefix};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l],a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {val,val};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {0,oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        char c; cin >> c;
        a[i] = (c == '(' ? 1 : -1);
    }
    build(1,1,n);
    while(m--) {
        int type; cin >> type;
        if(type == 0) {
            int i; char ch; cin >> i >> ch;
            int val = (ch == '(' ? 1 : -1);
            update(1,1,n,i,val);
        }
        else {
            int l,r; cin >> l >> r;
            Node query = get(1,1,n,l,r), s1 = get(1,1,n,1,l-1);
            if(query.prefix >= 0 && query.sum == 0) cout << 1;
            else cout << 0;
            // cout << l << ' ' << r << ' ' << query.sum << ' ' << query.prefix << '\n';
            // cout << 1;
        }
    }
    return 0;
}