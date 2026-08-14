#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,m;
int a[MM],b[MM],cnt[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> b[i];
    int res = 0;
    for(int i = 1,j = 1;j <= n;j++) {
        cnt[ a[j] ]++;
        while(i <= n && cnt[ a[j] ] > b[ a[j] ]) {
            cnt[ a[i] ]--;
            i++;
        }
        res = max(res,j - i + 1);
    }
    cout << res;
    return 0;
}