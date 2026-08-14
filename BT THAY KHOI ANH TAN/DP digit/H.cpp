#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
ll n,k,x,y,vx[MM],vy[MM];
ll dp[MM][MM];

ll f(ll a,ll b)
{
    if(a <= 0 || b <= 0) return 0;
    if(dp[a][b] != -1) return dp[a][b];
    ll s1 = f(a - 1,b), s2 = f(a,b - 1);
    dp[a][b] = max(s1,s2) + (vx[a] * vy[b] + 2 * vx[a] + 3 * vy[b]) % k;
    return dp[a][b];
}

vector<int> v1,v2;
void process(int x,int y)
{
    while(x > 0) {
        v1.push_back(x);
        x /= 2;
    }
    while(y > 0) {
        v2.push_back(y);
        y /= 2;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    for(int i = 0;i < v1.size();i++)
        vx[i + 1] = v1[i];
    for(int i = 0;i < v1.size();i++)
        vy[i + 1] = v2[i];
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
    cin >> n >> k >> x >> y;
    ll res = 0;
    memset(dp,-1,sizeof(dp));
    process(x,y);
    x = lower_bound(v1.begin(),v1.end(),x) - v1.begin() + 1;
    y = lower_bound(v2.begin(),v2.end(),y) - v2.begin() + 1;
    cout << f(x,y);
    return 0;
}