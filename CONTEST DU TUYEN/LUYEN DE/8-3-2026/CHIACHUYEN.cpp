#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,K;
ll w[MM],ps[MM];

ll C(int i,int j)
{
    ll ans = (ps[j] - ps[i - 1]) * (j - i + 1);
    return ans;
}

const int MS12 = 2007;
namespace subtask12
{
    ll dp[MS12][51],opt[MS12][51];    
    void solve()
    {
        for(int i = 1;i <= n;i++) ps[i] = ps[i - 1] + w[i];

        for(int i = 1;i <= n;i++)
            for(int j = 0;j <= K;j++)
                dp[i][j] = oo;

        for(int i = 1;i <= n;i++) dp[i][1] = C(1,i);
        for(int k = 2;k <= K;k++) {

            for(int i = k;i <= n;i++) {

                ll flag = oo, optj = i;

                for(int j = i;j >= 1;j--) {
                    dp[i][k] = min(dp[i][k],dp[j - 1][k - 1] + C(j,i));
                }

            }

        }
        cout << dp[n][K];
    }
}

namespace sol
{
    vector<ll> cur,nxt;

    void dnc(int L,int R,int optL,int optR)
    {
        if(L > R) return;

        int mid = (L + R) / 2;

        ll posL = -1, bestL = oo;
        for(int i = optL;i <= min(mid,optR);i++) {
            ll cost = cur[i - 1] + C(i,mid);
            if(cost < bestL) {
                bestL = cost;
                posL = i;
            }
        }

        nxt[mid] = bestL;
        dnc(L,mid - 1,optL,posL);
        dnc(mid + 1,R,posL,optR);
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) ps[i] = ps[i - 1] + w[i];
        cur.resize(n + 1);
        nxt.resize(n + 1);
        for(int i = 1;i <= n;i++) {
            cur[i] = C(1,i);
        }

        for(int k = 2;k <= K;k++) {
            dnc(1,n,1,n);
            cur = nxt;
        }

        cout << cur[n];
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
    cin >> n >> K;
    for(int i = 1;i <= n;i++) cin >> w[i];
    sol::solve();
    return 0;
}