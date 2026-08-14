#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int LOG = 19;
ll n,K,D;
ll a[MM],stmax[MM][LOG + 1],stmin[MM][LOG + 1];
map<ll,int> mp;

ll getmax(int l,int r)
{
    int k = __lg(r - l + 1);
    return max(stmax[l][k],stmax[r - (1 << k) + 1][k]);
}

ll getmin(int l,int r)
{
    int k = __lg(r - l + 1);
    return min(stmin[l][k],stmin[r - (1 << k) + 1][k]);
}

namespace subtask1
{
    void solve()
    {
        int res = 1;
        for(int i = 1;i <= n;i++) {
            int cntdif = 0;
            for(int j = i;j <= n;j++) {

                if(mp.find(a[j]) == mp.end()) {
                    mp[ a[j] ] = 1;
                    cntdif++;
                }

                if(getmax(i,j) - getmin(i,j) > K || cntdif > D) break;

                res = max(res,j - i + 1);
            }

            mp.clear();
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "B00493"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".ans","w",stdout);
    }
    cin >> n >> K >> D;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        stmax[i][0] = stmin[i][0] = a[i];
    }

    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            stmax[i][j] = max(stmax[i][j - 1],stmax[i + (1 << (j - 1))][j - 1]);
            stmin[i][j] = min(stmin[i][j - 1],stmin[i + (1 << (j - 1))][j - 1]);
        }

    subtask1::solve();
    return 0;
}