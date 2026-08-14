#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 50000 + 7;
ll n,k,T,a[MM];
ll ps[MM];

vector<ll> old,nxt;

ll C(int l,int r)
{
    ll sum = ps[r] - ps[l - 1] - T;
    return sum * sum;
}

void dnc(int l,int r,int optl,int optr)
{
    if(l > r) return;
    int mid = (l + r) / 2;

    ll best_L = oo, pos_L = l;
    for(int i = optl;i <= min(optr,mid);i++) {
        ll cost = old[i - 1] + C(i,mid);
        if(cost < best_L) {
            best_L = cost;
            pos_L = i;
        }
    }

    nxt[mid] = best_L;
    dnc(l,mid - 1,optl,pos_L);
    dnc(mid + 1,r,pos_L,optr);
}

namespace subtask1
{
    ll dp[301][11],opt[301][11];
    void solve()
    {
        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= k;j++) 
                dp[i][j] = oo;

        for(int i = 1;i <= n;i++)
            dp[i][1] = C(1,i);

        for(int d = 2;d <= k;d++) {
            for(int i = 1;i <= n;i++) {
                ll best_L = oo, pos_L = i;
                for(int j = 1;j <= i;j++) {
                    ll cost = dp[j - 1][d - 1] + C(j,i);
                    if(cost < best_L) {
                        best_L = cost;
                        pos_L = j;
                    }
                }
                dp[i][d] = best_L;
                opt[i][d] = pos_L;

                if(i > 1) assert(opt[i - 1][d] <= opt[i][d]);
            }
        }

        cout << dp[n][k];
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
    cin >> n >> k >> T;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    // subtask1::solve();
    old.assign(n + 1,oo);
    nxt.resize(n + 1,oo);
    for(int i = 1;i <= n;i++) {
        old[i] = C(1,i);
        // cout << old[i] << ' ';
    }
    for(int i = 2;i <= k;i++) {
        dnc(1,n,1,n);
        old = nxt;
    }
    cout << old[n];
    return 0;
}