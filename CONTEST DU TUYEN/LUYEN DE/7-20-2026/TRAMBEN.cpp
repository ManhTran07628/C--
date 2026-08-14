#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll> 
const int MM = 1e6 + 7;
int n,K;
ll x[MM],w[MM];

const int MS1 = 301;
namespace subtask1
{
    ll dp[MS1][31] = {}, F[MS1][MS1] = {};
    void solve()
    {
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i <= n;i++) {
                F[i][j] = abs(x[i] - x[j]) * w[i];
                F[i][j] += F[i - 1][j];
            }
        }

        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= K;j++)
                dp[i][j] = oo;


        dp[0][0] = 0;

        for(int i = 1;i <= n;i++) {
            for(int k = 1;k <= min(i,K);k++) {
                for(int j = 1;j <= i;j++) {
                    
                    for(int pos = j;pos <= i;pos++) {
                        ll cost = F[i][pos] - F[j - 1][pos];
                        dp[i][k] = min(dp[i][k],dp[j - 1][k - 1] + cost);
                    }

                }
            }
        }
        cout << dp[n][K];
    }
}

namespace sol
{
    ll G[MM],ps[MM];


    int bins(int L,int R)
    {
        ll res = L, avg = (ps[R] - ps[L - 1]) / 2;
        while(L <= R) {
            ll mid = (L + R) / 2;
            if(ps[mid] - ps[L - 1] >= avg) {
                res = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        return res;
    }

    ll C(int L,int R)
    {
        int m = bins(L,R);
        // for(int i = L;i <= R;i++) {
        //     sum += w[i] * abs(x[i] - x[m]);
        // } 
        ll sum = x[m] * (ps[m] - ps[L - 1]) - (G[m] - G[L - 1]) 
        + (G[R] - G[m]) - x[m] * (ps[R] - ps[m]);
        return sum;
    }

    vector<ll> old_dp,new_dp;

    void dnc(int L,int R,int optL,int optR)
    {
        if(L > R) return;

        int mid = (L + R) / 2;
        ll best_L = oo, pos_L = -1;

        for(int i = optL;i <= min(mid,optR);i++) {
            ll cost = old_dp[i - 1] + C(i,mid);
            if(cost < best_L) {
                best_L = cost;
                pos_L = i;
            }
        }

        new_dp[mid] = best_L;

        dnc(L,mid - 1,optL,pos_L);
        dnc(mid + 1,R,pos_L,optR);
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            G[i] = G[i - 1] + x[i] * w[i];
            ps[i] = ps[i - 1] + w[i];
        }
        old_dp.assign(MM,oo);
        new_dp.assign(MM,oo);

        old_dp[0] = new_dp[0] = 0;

        for(int i = 1;i <= n;i++) {
            old_dp[i] = C(1,i);
        }

        for(int i = 2;i <= K;i++) {
            dnc(1,n,1,n);
            old_dp = new_dp;
        }

        cout << old_dp[n];
        // cout << C(1,1);
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
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 1;i <= n;i++) cin >> w[i];
    sol::solve();
    return 0;
}
