#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k,a[MM],cnt[MM];

vector<ll> old,nxt;

void dnc(int l,int r,int optl,int optr)
{
    if(l > r) return;
    int mid = (l + r) / 2;

    ll best_L = oo;
    int pos_L = optl;

    ll C = 0;
    for(int i = min(mid,optr);i >= optl;i--) {
        C += cnt[ a[i] ];

        ll cost = C + old[i - 1];

        if(cost < best_L) {
            best_L = cost;
            pos_L = i;
        }

        cnt[ a[i] ]++;
    }

    nxt[mid] = best_L;

    for(int i = min(mid,optr);i >= optl;i--) cnt[ a[i] ] = 0;

    dnc(l,mid - 1,optl,pos_L);
    dnc(mid + 1,r,pos_L,optr);
}

namespace subtask1
{
    ll dp[501][501],opt[501][501];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            dp[i][1] = dp[i - 1][1] + cnt[ a[i] ];
            cnt[ a[i] ]++;
        }
        dp[0][0] = oo;

        for(int i = 1;i <= n;i++) cnt[ a[i] ] = 0;

        for(int d = 2;d <= k;d++) {
            for(int i = 1;i <= n;i++) {

                ll C = 0, best = oo, pos = i;
                
                for(int j = i;j >= 1;j--) {
                    C = C + cnt[ a[j] ];
                    cnt[ a[j] ]++;

                    ll cost = C + dp[j - 1][d - 1];
                    if(best > cost) {
                        best = cost;
                        pos = j;
                    }
                    best = min(best,cost);
                }

                dp[i][d] = best;
                opt[i][d] = pos;

                // if(i > 1) assert(opt[i - 1][d] <= opt[i][d]);

                for(int j = i;j >= 1;j--) cnt[ a[j] ] = 0;

            }
        }

        cout << dp[n][k];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "Z"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".ans","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // old.assign(n + 1,0);
    // nxt.assign(n + 1,0);

    // for(int i = 1;i <= n;i++) {
    //     old[i] = old[i - 1] + cnt[ a[i] ];
    //     cnt[ a[i] ]++;
    // }
    // old[0] = nxt[0] = oo;

    // for(int i = 1;i <= n;i++) cnt[ a[i] ] = 0;

    // for(int i = 2;i <= k;i++) {
    //     dnc(1,n,1,n);
    //     old = nxt;
    // }
    // cout << old[n];
    subtask1::solve();
    return 0;
}