#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,t,trace[MM];
struct Edge{int a,b,w,id;} emp[MM];


void init()
{
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> emp[i].a >> emp[i].b >> emp[i].w;
        emp[i].id = i;
    }
}

void coordcompress()
{
    vector<int> v; v.push_back(t);
    for(int i = 1;i <= n;i++) {
        v.push_back(emp[i].a);
        v.push_back(emp[i].b);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        emp[i].a = lower_bound(v.begin(),v.end(),emp[i].a) - v.begin() + 1;
        emp[i].b = lower_bound(v.begin(),v.end(),emp[i].b) - v.begin() + 1;
    }
    t = lower_bound(v.begin(),v.end(),t) - v.begin() + 1;
}

struct Node{ll val,id;};
Node st[MM * 4], lazy[MM * 4];

void fix(int id,int l,int r)
{
    if(lazy[id].val == oo) return;
    if(st[id].val > lazy[id].val) st[id] = lazy[id];
    if(l != r) {
        if(lazy[id*2].val > lazy[id].val) lazy[id*2] = lazy[id];
        if(lazy[id*2+1].val > lazy[id].val) lazy[id*2+1] = lazy[id];
    }
    lazy[id] = {oo,0};
}

void update(int id,int l,int r,int u,int v,ll val,int nxt)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        if(lazy[id].val > val) lazy[id] = {val,nxt};
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val,nxt);
    update(id*2+1,mid+1,r,u,v,val,nxt);
    if(st[id*2].val > st[id*2+1].val) st[id] = st[id*2+1];
    else st[id] = st[id*2];
}

Node get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {oo,1};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    Node left = get(id*2,l,mid,u,v), right = get(id*2+1,mid+1,r,u,v);
    if(left.val > right.val) return right;
    return left;
    // return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    coordcompress();
    for(int i = 1;i < MM * 4;i++) st[i].val = lazy[i].val = oo;
    update(1,1,t,1,1,0,0);
    sort(emp+1,emp+n+1,[] (Edge a, Edge b){
        if(a.b != b.b) return a.b < b.b;
        return a.a < b.a;
    });
    // for(int i = 1;i <= n;i++) cout << emp[i].a << ' ' << emp[i].b << '\n';
    ll last_val = oo, cur = -1;
    for(int i = 1;i <= n;i++) {
        Node val = get(1,1,t,emp[i].a,emp[i].b);
        trace[i] = val.id;
        update(1,1,t,emp[i].a,emp[i].b,val.val + emp[i].w,i);
        if(emp[i].b >= t && val.val + emp[i].w < last_val) {
            cur = i;
            last_val = val.val + emp[i].w;
        }
    }
    cout << get(1,1,t,t,t).val << '\n';
    vector<int> ans;
    while(cur != 0) {
        ans.push_back(emp[cur].id); 
        cur = trace[cur];
    }
    // reverse(ans.begin(), ans.end());
    for(auto x:ans) cout << x << ' ';
    return 0;
}