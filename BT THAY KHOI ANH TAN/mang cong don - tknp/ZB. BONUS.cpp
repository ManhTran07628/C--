#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1005;
ll a[MAXN][MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n-k+1;i++) {
        for(int j = 1;j <= n-k+1;j++) {
            int i1 = i+k-1;
            int j1 = j+k-1;
            ll s = a[i1][j1]-a[i1][j-1]-a[i-1][j1]+a[i-1][j-1];
            ans = max(ans,s);
        }
    }
    cout << ans;
    return 0;
}