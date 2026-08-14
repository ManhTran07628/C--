#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,K;
ll x[MM];


const int MS3 = 207;
namespace subtask3
{
    ll dp[MS3][MS3], ps[MS3];
    ll opt[MS3][MS3];

    ll C(ll l,ll r)
    {
        int med = l + (r - l + 1) / 2;
        ll d1 = (med - l + 1) * x[med] - (ps[med] - ps[l - 1]);
        ll d2 = (ps[r] - ps[med]) - (r - med) * x[med];
        return d1 + d2;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) ps[i] = ps[i - 1] + x[i];
        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= n;j++)
                dp[i][j] = oo;

        for(int i = 1;i <= n;i++)
            dp[i][1] = C(1,i);
        
        for(int k = 2;k <= K;k++) {

            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= i;j++) {
                    ll cost = dp[j - 1][k - 1] + C(j,i);
                    dp[i][k] = min(dp[i][k],cost);
                }

            }

        }

        cout << dp[n][K];
    }
}

namespace subtask4
{
    ll ps[MS3];
    vector<ll> cur,nxt;

    ll C(ll l,ll r)
    {
        int med = l + (r - l + 1) / 2;
        ll d1 = (med - l + 1) * x[med] - (ps[med] - ps[l - 1]);
        ll d2 = (ps[r] - ps[med]) - (r - med) * x[med];
        return d1 + d2;
    }

    void dnc(int L,int R,int optL,int optR)
    {
        if(L > R) return;
        int mid = (L + R) / 2;

        int pos_L = L;
        ll best_L = oo;
        for(int i = optL;i <= min(optR,mid);i++) {
            ll cost = cur[i - 1] + C(i,mid);
            if(cost < best_L) {
                best_L = cost;
                pos_L = i;
            }
        }

        nxt[mid] = best_L;
        dnc(L,mid - 1,optL,pos_L);
        dnc(mid + 1,R,pos_L,optR);
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) ps[i] = ps[i - 1] + x[i];
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
    #define taskname "TESTROOM"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> K;
    for(int i = 1;i <= n;i++) cin >> x[i];
    sort(x+1,x+n+1);
    subtask4::solve();
    return 0;
}