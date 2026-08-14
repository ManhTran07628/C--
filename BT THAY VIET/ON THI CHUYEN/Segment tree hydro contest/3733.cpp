#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],lz1[N*4],lz2[N*4],vt[N*4];

void build(ll id,ll l,ll r)
{
    if(l == r) {
        vt[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    vt[id] = vt[id*2] + vt[id*2+1];
}

void update(ll id,ll l,ll r,ll u,ll v,ll x)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        vt[id] += x;
        lz1[id] += x;
        lz2[id] *= x;
    }
    ll mid = (l+r)/2;
    lz1[id*2] += lz1[id];
    lz1[id*2+1] += lz1[id];
    vt[id*2] += lz1[id]*(mid-l+1);
    vt[id*2+1] += lz1[id]*(r-mid);
    lz1[id] = 0;

    lz2[id*2] += lz2[id];
    lz2[id*2+1] += lz2[id];
    vt[id*2] *= lz2[id];
    vt[id*2=1] *= lz2[id];
    lz2[id] = 1;

    update(id*2)

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

    return 0;
}