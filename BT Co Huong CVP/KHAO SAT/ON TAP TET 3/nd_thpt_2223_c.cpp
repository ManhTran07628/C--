#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int cnt[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "AODAI"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    int res = cnt[4];
    
    int k1 = min(cnt[1],cnt[3]);
    res += k1;
    cnt[1] -= k1; cnt[3] -= k1;

    int k2 = min(cnt[1] / 2,cnt[2]);
    res += k2;
    cnt[1] -= k2 * 2;
    cnt[2] -= k2; 

    if(cnt[1] == 1 && cnt[2] > 0) {
        res++;
        cnt[1]--;
        cnt[2]--;
    }

    int k3 = cnt[2] / 2;
    res += k3;
    cnt[2] -= k3 * 2;

    int k4 = cnt[1] / 4;
    res += k4;
    cnt[1] -= k4 * 4;

    if(cnt[1] > 0) {
        res++;
        cnt[1] = 0;
    }

    res += cnt[1] + cnt[2] + cnt[3];
    cout << res;
    return 0;
}