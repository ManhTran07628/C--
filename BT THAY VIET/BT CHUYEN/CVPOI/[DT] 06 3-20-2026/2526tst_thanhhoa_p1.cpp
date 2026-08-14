#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
int n,A[MM];


namespace subtask1
{
    int cnt[MM];
    void solve()
    {
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            ll sum = 0;
            for(int j = i;j <= n;j++) {
                cnt[A[j]]++;
                if(cnt[A[j]] % 2 == 0) sum -= A[j];
                else sum += A[j];
                res += 1ll * (j - i + 1) * sum; res %= MOD;
            }

            for(int j = i;j <= n;j++) cnt[A[j]] = 0;
        }
        cout << res;
    }
}

namespace subtask2
{
    int x[MM],y[MM],cnt[MM];
    ll ps[MM];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            if(!x[ A[i] ]) x[ A[i] ] = i;
            else y[ A[i] ] = i;
            cnt[ A[i] ]++;
            ps[i] = ps[i-1] + i; ps[i] %= MOD;
        }
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            int a = x[i], b = y[i];
            if(a == 0 && b == 0) continue;
            if(b == 0) {
                a = 1, b = n;
                ll sum1 = a * (ps[b - 1] - ps[a - 1]) % MOD - (b - a) * (ps[a - 1]) % MOD;
                continue;
            }
            ll sum1 = a * (ps[b - 1] - ps[a - 1]) % MOD - (b - a) * (ps[a - 1]) % MOD;
            ll sum2 = (b - 1) * (ps[n] - ps[b]) % MOD  - (n - b + 1) * (ps[b - 1] - ps[a - 1]) % MOD;
            res += i * (sum1 + sum2) % MOD; res %= MOD;
        }
        cout << res;

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
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> A[i];
    subtask2::solve();
    return 0;
}