#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],vt[N*4],lazy[N*4];

void build(ll id,ll l,ll r)
{
    if(l == r) {
        vt[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    vt[id] = vt[id*2]+vt[id*2+1];
}

void update(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
        
    }
}

void update()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }

    return 0;
}