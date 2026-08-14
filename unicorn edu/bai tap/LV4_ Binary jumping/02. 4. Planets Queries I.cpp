#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int LOG = 30;
int n,q,up[MM][LOG + 1];


void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        int t; cin >> t;
        up[i][0] = t;
    }
}

void process()
{
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)   
            up[i][j] = up[ up[i][j-1] ][j-1];
}

int find_nxt_planet(int x,int k)
{
    int cur = x;
    for(int j = LOG;j >= 0;j--)
        if(k >> j & 1)
            cur = up[cur][j];
    return cur;
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
    init();
    process();
    while(q--) {
        int x,k; cin >> x >> k;
        cout << find_nxt_planet(x,k) << '\n';
    }
    return 0;
}   