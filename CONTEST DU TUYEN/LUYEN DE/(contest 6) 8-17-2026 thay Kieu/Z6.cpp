#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,q;
ll a[MM];

struct Node{ll u,max_u;} st[MM * 4];
ll lazy[MM * 4];

void fix(int id,int l,int r)
{
    if(lazy[id] == oo) return;
    st[id].u += lazy[id];
    st[id].u
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
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];

    return 0;
}