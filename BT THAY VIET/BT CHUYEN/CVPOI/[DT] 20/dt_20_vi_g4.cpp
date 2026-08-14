#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;

int bit1[MM],bit2[MM];

void update(int x,int bit[],int val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

int get(int x,int bit[])
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
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
    for(int i = 1;i <= m;i++) {
        int q,l,r; cin >> q >> l >> r;
        if(q == 1) {
            update(l,bit1,1);
            update(r,bit2,1);
        }
        else {
            cout << get(r,bit1) - get(l - 1,bit2) << '\n';
        }
    }
    return 0;
}