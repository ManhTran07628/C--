#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll n,l,r; 

namespace brute
{
    vector<ll> vec;

    void dfs(ll n)
    {
        if(n == 0 || n == 1) {
            vec.push_back(n);
            return;
        }
        ll v1 = n / 2, v2 = n % 2, v3 = n / 2;
        dfs(v1);
        dfs(v2);
        dfs(v3);
    }

    void solve()
    {
        dfs(n);
        int cnt = 0;
        for(int i = l - 1;i < r;i++) cnt += (vec[i] == 1);
        cout << cnt;
    }
}

namespace sol
{
    vector<ll> vec;
    ll val[MM];

    struct Node
    {
        ll num0 = 0,num1 = 0;
    } dp[MM];

    ll sumL = 0, sumR = 0;
    void dfs(int id,ll sum,ll &res)
    {
        if(id == 1 || id == 2) {
            res += dp[id].num1;
            return;
        }
        ll v1 = id - 1, v2 = (val[id] % 2 == 1 ? 2 : 1), v3 = id - 1;

        if(sum <= dp[v1].num0 + dp[v1].num1) {
            dfs(v1,sum,res);
            return;
        }

        sum -= (dp[v1].num0 + dp[v1].num1);
        res += dp[v1].num1;

        if(sum <= dp[v2].num0 + dp[v2].num1) {
            dfs(v2,sum,res);
            return;
        }

        sum -= (dp[v2].num0 + dp[v2].num1);
        res += dp[v2].num1;

        dfs(v3,sum,res);
        return;
    }

    void solve()
    {
        ll k = n;
        while(k > 1) {
            vec.push_back(k);
            k /= 2;
        }

        dp[1].num0 = 1; 
        dp[2].num1 = 1; 

        vec.push_back(1);
        vec.push_back(0);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        for(int i = 0;i < vec.size();i++) val[i + 1] = vec[i];
        int sz = vec.size();

        for(int i = 3;i <= sz;i++) {
            ll v2 = val[i] % 2;
            dp[i].num0 += dp[i - 1].num0 * 2;
            dp[i].num1 += dp[i - 1].num1 * 2;
            if(v2 == 0) dp[i].num0++;
            else dp[i].num1++;
        }

        dfs(sz,r,sumR);
        dfs(sz,l - 1,sumL);
        cout << sumR - sumL;
    }
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
    cin >> n >> l >> r;
    if(n <= (1 << 15)) brute::solve();
    else sol::solve();
    return 0;
}