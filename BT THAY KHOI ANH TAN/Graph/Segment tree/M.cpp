#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5e5+7;
int n,x[MM],st[MM*4];

void readinput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> x[i];
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = 1;
        return; 
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
}

void update(int id,int l,int r,int pos)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = 0;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int pos)
{
    if(l == r) return l;
    int mid = (l+r)/2;
    if(st[id*2] >= pos) return get(id*2,l,mid,pos);
    return get(id*2+1,mid+1,r,pos-st[id*2]);
}


void solve()
{
    build(1,1,n);
    for(int i = 1;i <= n;i++) {
        int p;
        cin >> p;
        cout << x[get(1,1,n,p)] << ' ';
        update(1,1,n,get(1,1,n,p));
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}