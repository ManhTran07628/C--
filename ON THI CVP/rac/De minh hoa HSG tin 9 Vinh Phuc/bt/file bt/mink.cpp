#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+7;
int n,k,a[N],st[N*4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = min(st[id*2],st[id*2+1]);
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 1e9;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        build(1,1,n);
        for(int i = 1;i <= n-k+1;i++) {
            cout << get(1,1,n,i,i+k-1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}