#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
ll n,k,a[MM];
ll ps[MM];

namespace subtask1
{

    ll cost(int L,int R,vector<int> vec)
    {
        int mid = (k + 1) / 2;
        ll res = 0;
        for(int i = 1;i <= k;i++) res += abs(vec[i] - vec[mid]);
        return res;
    }

    void solve()
    {
        ll res = 0;
        for(int i = 1;i + k - 1 <= n;i++) {
            vector<int> vec;
            vec.push_back(0);
            for(int j = i;j <= i + k - 1;j++) vec.push_back(a[j]);
            sort(vec.begin(),vec.end());
            
            cout << cost(i,i + k - 1,vec) << ' ';
        }
    }
}

namespace subtask2
{
    ll pf[MM][101];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= 100;j++) {
                pf[i][j] += pf[i - 1][j];
            }
            pf[i][ a[i] ]++;
        }

        for(int i = 1;i + k - 1 <= n;i++) {

            int mid = (k + 1) / 2;
            int median = 1;

            for(int j = 1;j <= 100;j++) {
                int cnt = pf[i + k - 1][j] - pf[i - 1][j];
                mid -= cnt;
                if(mid <= 0) {
                    median = j;
                    break;
                }
            }

            ll res = 0;
            for(int j = 1;j <= median;j++) {
                int cnt = pf[i + k - 1][j] - pf[i - 1][j];
                res += 1ll * median * cnt - 1ll * cnt * j;
            }

            for(int j = median + 1;j <= 100;j++) {
                int cnt = pf[i + k - 1][j] - pf[i - 1][j];
                res += 1ll * cnt * j - 1ll * median * cnt;
            }

            cout << res << ' ';
        }
    }
}

namespace subtask3
{
    ll cost(int L,int R)
    {
        int mid = L + (k + 1) / 2 - 1;
        ll s1 = a[mid] * (mid - L + 1) - (ps[mid] - ps[L - 1]);
        ll s2 = (ps[R] - ps[mid]) - a[mid] * (R - mid);
        return s1 + s2;
    }

    void solve()
    {
        ll res = 0;
        for(int i = 1;i + k - 1 <= n;i++) {
            cout << cost(i,i + k - 1) << ' ';
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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i - 1] + a[i];
    }
    if(n <= 2000) subtask1::solve();
    else if(*max_element(a+1,a+n+1) <= 100) subtask2::solve();
    else subtask3::solve();
    // subtask2::solve();
    return 0;
}