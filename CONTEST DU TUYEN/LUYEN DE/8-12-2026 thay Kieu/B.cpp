#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int LOG = 19;
int n,a[MM];
ll K;
int stmin[MM][LOG + 1],stmax[MM][LOG + 1];

int get_min(int l,int r)
{
    int k = __lg(r - l + 1);
    return min(stmin[l][k],stmin[r - (1 << k) + 1][k]);
}

int get_max(int l,int r)
{
    int k = __lg(r - l + 1);
    return max(stmax[l][k],stmax[r - (1 << k) + 1][k]);
}

int bins(int l,int r)
{
    int res = r;
    int old_r = r;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(get_max(mid,old_r) - get_min(mid,old_r) <= K) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        stmin[i][0] = stmax[i][0] = a[i];
    }

    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            stmin[i][j] = min(stmin[i][j - 1],stmin[i + (1 << (j - 1))][j - 1]);
            stmax[i][j] = max(stmax[i][j - 1],stmax[i + (1 << (j - 1))][j - 1]);
        }

    ll res = 0;
    for(int i = 1;i <= n;i++) {
        res += (i - bins(1,i) + 1);
        // cout << bins(1,i) << ' ' << i << '\n';
    }
    cout << res;
    return 0;
}