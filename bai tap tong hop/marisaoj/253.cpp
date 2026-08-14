#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll prime[MM];
void sieve()
{
    for(int i = 1;i < MM;i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(ll i = 2;i*i < MM;i++)
        if(prime[i])
            for(int j = i*2;j < MM;j+=i)
                prime[j] = 0;
}

namespace sol
{
    ll dp[18][2][170],k;
    
    ll f(int id,int tight,int cntsum,string s)
    {
        int n = s.size();
        if(id == n) return prime[cntsum];
        ll memo = dp[id][tight][cntsum];
        if(memo != -1) return memo;
    
        int lim = !tight ? 9 : s[id] - '0';
        memo = 0;
        for(int i = 0;i <= lim;i++) {
            int new_tight = tight && i == lim;
            int new_cntsum = cntsum + i;
            memo += f(id+1,new_tight,new_cntsum,s);
        }
        dp[id][tight][cntsum] = memo;
        return memo;
    }
    
    
    bool check(ll a,ll k)
    {
        string s = to_string(a);
        memset(dp,-1,sizeof(dp));
        ll cnt = f(0,1,0,s);
        return cnt >= k;
    }
    
    void solve()
    {
        sieve();
        cin >> k;
        ll l = 0,r = oo,ans = 0;
        while(l <= r) {
            ll mid = (l+r)/2;
            if(check(mid,k)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
            // cout << mid << '\n';
        }
        cout << ans << '\n';
    }
}

namespace solb
{

    bool check(int k)
    {
        int cnt = 0;
        while(k > 0) {
            cnt += k % 10;
            k /= 10;
        }
        return prime[cnt];
    }

    void solve() {
        sieve();
        int cnt = 0;
        for(int i = 0;i <= 241;i++) {
            if(check(i)) cnt++;
        }
        cout << cnt;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sol::solve();
    // solb::solve();
    return 0;
}