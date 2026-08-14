#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int t;
ll ovnum[MM];

bool check(int k)
{
    int cnt = 500;
    while(k > 1 && cnt > 0) {
        string s = to_string(k);
        int sum = 0;
        for(auto c:s) sum += (c - '0') * (c - '0');
        k = sum;
        cnt--;
    }
    return k == 1;
}

ll dp[17][1300];

ll f(int id,int tight,ll sum,string s)
{
    if(id == s.size()) return ovnum[sum];
    int sz = s.size() - id;
    ll memo = dp[sz][sum];
    if(memo != -1 && tight == 0) return memo;
    memo = 0;
    ll lim = (tight ? s[id] - '0' : 9);
    for(int i = 0;i <= lim;i++) {
        int new_tight = (tight && i == lim);
        ll new_sum = sum + i * i;
        memo += f(id+1,new_tight,new_sum,s);
    }
    if(tight == 0) dp[sz][sum] = memo;
    return memo;
}

ll solve(ll a)
{
    string s = to_string(a);
    return f(0,1,0,s);
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

    for(int i = 1;i <= 1500;i++) {
        ovnum[i] = check(i);
        // if(ovnum[i]) cout << i << ' ';
    }

    memset(dp,-1,sizeof(dp));
    
    cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        ll L = n + 1, R = 1e17, res = 0;
        while(L <= R) {
            ll mid = (L + R) / 2;
            if(solve(mid) - solve(n) >= m) {
                res = mid;
                R = mid - 1;
            }
            else L = mid + 1;
            // cout << mid << ' ' << solve(mid) - solve(L - 1) << '\n';
        }

        cout << res << '\n';
    }
    return 0;
}