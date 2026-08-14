#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,q;
ll st[MM * 4];

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    while(q--) {
        char c;
        cin >> c;
        if(c == 'S') {
            int i,j;
            cin >> i >> j;
            update(1,1,n,i,j);
        }
        else {
            int i,j;
            cin >> i >> j;
            cout << get(1,1,n,i,j) << '\n';
        }
    }
    return 0;
}