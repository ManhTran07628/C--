#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q,newid[MM],p[MM];


struct dl{char type;int a,b;} qr[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> p[i];
    }
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].type >> qr[i].a >> qr[i].b;
    }
}

int st[MM*4];


void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] += val;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void solve()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) {
        v.push_back(p[i]);
    }
    for(int i = 1;i <= q;i++) {
        v.push_back(qr[i].b);
        if(qr[i].type == '?') v.push_back(qr[i].a);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        newid[i] = lower_bound(v.begin(),v.end(),p[i]) - v.begin() + 1;
    }
    for(int i = 1;i <= q;i++) {
        qr[i].b = lower_bound(v.begin(),v.end(),qr[i].b) - v.begin() + 1;
        if(qr[i].type == '?') 
            qr[i].a = lower_bound(v.begin(),v.end(),qr[i].a) - v.begin() + 1;
    }
    
    int lim = v.size();
    for(int i = 1;i <= n;i++) {
        update(1,1,lim,newid[i],1);
    }
    for(int i = 1;i <= q;i++) {
        if(qr[i].type == '!') {
            update(1,1,lim,newid[qr[i].a],-1);
            update(1,1,lim,qr[i].b,1);
            newid[qr[i].a] = qr[i].b; 
        }
        else cout << get(1,1,lim,qr[i].a,qr[i].b) << '\n';
    }
    
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}