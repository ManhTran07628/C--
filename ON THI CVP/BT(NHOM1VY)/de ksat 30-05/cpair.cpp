#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int dem[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i]%2==0 && a[i]%6 != 0) dem[2]++;
        if(a[i]%3==0 && a[i]%6 != 0) dem[3]++;
        if(a[i]%6==0) dem[6]++;
    }
    int ans = 0;
    int d1 = dem[2],d2 = dem[3],d3 = dem[6];
    ans = d1*d2+d3*(n-d3)+(d3-1)*d3/2;
    cout << ans << '\n';
    return 0;
}