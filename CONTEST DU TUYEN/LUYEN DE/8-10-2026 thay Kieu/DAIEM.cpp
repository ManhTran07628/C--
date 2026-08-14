#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,q,qr[MM];
ll a[MM],k;

namespace subtask1
{
    void solve()
    {
        for(int t = 1;t <= q;t++) {
            int x = qr[t];
            ll res = 0;
            for(int i = 1;i <= n;i++) {
                for(int j = i + x - 1;j <= n;j++) {
                    
                    ll mmin = oo, mmax = -oo;
                    for(int d = i;d <= j;d++) {
                        mmax = max(mmax,a[d]);
                        mmin = min(mmin,a[d]);
                    }

                    if(mmax - mmin <= k) res++;
                }
            }

            cout << res << '\n';
        }
    }
}

namespace subtask2
{
    void solve()
    {
        for(int t = 1;t <= q;t++) {
            ll x = qr[t];
            ll res = x * (x + 1) / 2;
            cout << res << '\n';
        }
    }
}


const int LOG = 19;
namespace subtask3
{
    ll stmax[MM][LOG + 1],stmin[MM][LOG + 1],ps[MM] = {},d[MM] = {};

    ll getmax(int L,int R)
    {
        int K = __lg(R - L + 1);
        return max(stmax[L][K],stmax[R - (1 << K) + 1][K ]);
    }

    ll getmin(int L,int R)
    {
        int K = __lg(R - L + 1);
        return min(stmin[L][K],stmin[R - (1 << K) + 1][K]);
    }

    int bins(int L,int R)
    {
        int old_R = R;
        int res = R;
        while(L <= R) {
            int mid = (L + R) / 2;
            if(getmax(mid,old_R) - getmin(mid,old_R) <= k) {
                res = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        return res;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) stmax[i][0] = stmin[i][0] = a[i];
        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i + (1 << j) - 1 <= n;i++) {
                stmax[i][j] = max(stmax[i][j - 1],stmax[i + (1 << (j - 1))][j - 1]);
                stmin[i][j] = min(stmin[i][j - 1],stmin[i + (1 << (j - 1))][j - 1]);
            }

        // cout << getmin(1,4) << ' ' << getmax(1,4) << '\n';
        vector<int> vec;
        ll res = 0;
        for(int j = 1;j <= n;j++) {
            int i = bins(1,j);
            vec.push_back(j - i + 1);
            // cout << i << ' ' << j << '\n';
        }
        sort(vec.begin(),vec.end());
        for(int i = 1;i <= n;i++) {
            d[i] = vec[i - 1];
            ps[i] = ps[i - 1] + d[i];
        }

        for(int t = 1;t <= q;t++) {
            ll x = qr[t];
            int pos = lower_bound(d+1,d+n+1,x) - d;

            if(pos > n) {
                cout << 0 << '\n';
                continue;
            }

            ll len = n - pos + 1;
            ll res = len + (ps[n] - ps[pos - 1]) - x * len;
            cout << res << '\n';
        }
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
    cin >> n >> q >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) cin >> qr[i];
    subtask3::solve();
    // if(n <= 300 && q <= 300) subtask1::solve();
    // else if(*max_element(a+1,a+n+1) - *min_element(a+1,a+n+1) <= k) subtask2::solve();
    // else subtask3::solve();
    return 0;
}