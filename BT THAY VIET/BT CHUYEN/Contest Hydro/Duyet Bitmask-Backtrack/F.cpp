#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[101],b[101],c[101],d[101];
map<int,int> mark;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    for(int i = 1;i <= k;i++) {
        cin >> c[i] >> d[i];
    }
    int ans = 0;
    for(int mask = 1;mask < (1 << k);mask++) {
        for(int i = 0;i < k;i++) {
            if((mask >> i) & 1) mark[c[i+1]]++;
            else mark[d[i+1]]++;
        }
        int cnt = 0;
        for(int i = 1;i <= m;i++) {
            if(mark[a[i]] > 0 && mark[b[i]] > 0) cnt++;
        }
        ans = max(ans,cnt);
        mark.clear();
    }
    cout << ans;
    return 0;
}