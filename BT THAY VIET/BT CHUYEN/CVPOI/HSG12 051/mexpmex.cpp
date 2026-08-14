#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 2e5 + 7;
int n,a[MM],b[MM];
vector<int> c;


int st[MM * 4];
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

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return oo;
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(st[id*2] < mid - l + 1) return get(id*2,l,mid,u,v);
    return get(id*2+1,mid+1,r,u,v);
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    for(int i = 1;i <= n;i++) {
        int val;
        if(i == 1) val = a[n];
        else val = a[i - 1];
        if(a[i] > n) {
            b[i] = b[i-1];
            continue;
        }
        update(1,0,n,val,1);
        b[i] = get(1,0,n,0,n);
    }
    for(int i = 0;i <= n;i++) update(1,0,n,i,0);
    
    for(int i = 1;i <= n;i++) update(1,0,n,b[i],1);
    cout << get(1,0,n,0,n);
    return 0;
}