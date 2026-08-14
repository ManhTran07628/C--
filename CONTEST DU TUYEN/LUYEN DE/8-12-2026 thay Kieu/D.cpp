#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MOD = 1e9 + 7;
const int MM = 2e5 + 7;
int n,L;
ll S,a[MM],ps[MM];

namespace subtask12
{
    ll dp[MM];
    void solve()
    {
        dp[0] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = i;j >= 1;j--) {
                ll sum = ps[i] - ps[j - 1];
                if(i - j + 1 > L || sum > S) break;
                dp[i] += dp[j - 1];
            }
        }
        cout << dp[n];
    }
}

namespace subtask3
{
    ll bit[MM],b[MM];

    void update(int x,ll val)
    {
        for(;x <= n + 1;x += (x & -x)) {
            bit[x] += val;
            bit[x] %= MOD;
        }
    }

    ll get(int x)
    {
        ll res = 0;
        for(;x > 0;x -= (x & -x)) {
            res += bit[x];
            res %= MOD;
        }
        return res;
    }

    ll get_range(int l,int r)
    {
        return (get(r) - get(l - 1) % MOD + MOD) % MOD;
    }

    int bins(int l,int r)
    {
        int old_r = r;
        int res = r;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(b[old_r] - b[mid - 1] <= S) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }

    void solve()
    {
        for(int i = 2;i <= n + 1;i++) {
            b[i] = b[i - 1] + a[i - 1];
        }

        update(1,1);
        for(int i = 2;i <= n + 1;i++) {
            int r = i;
            int l = max(2,i - L + 1);
            
            int j = bins(l,r);

            if(b[r] - b[j - 1] > S) continue;

            ll val = get_range(j - 1,r - 1);
            update(i,val);
        }

        cout << get_range(n+1,n+1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "D"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> S >> L;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    subtask3::solve();
    return 0;
}