#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 1;i <= m+1;i++) {
        for(int j = 1;j <= n+1;j++) {
            if(a[i][j] > 0) {
                ans++;
            }
            ans += abs(a[i][j] - a[i-1][j]);
            ans += abs(a[i][j] - a[i][j-1]);
        }
    }
    cout << ans;
    return 0;
}