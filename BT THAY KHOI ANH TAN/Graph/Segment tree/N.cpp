#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e5+7;
int n,m;
struct dl{int l,r,w;} a[MM];
pair<int,int> dp[MM];

void init()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].l >> a[i].r >> a[i].w;
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) {
        
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}