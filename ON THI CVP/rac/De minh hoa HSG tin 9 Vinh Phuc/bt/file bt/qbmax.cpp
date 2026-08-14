#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    ll n,m;
    cin >> m >> n;
    for(int i = 1;i <= m;i++ ) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        a[0][i] = a[m+1][i] = -1e9;
    }
    ll ans = -1e9;
    for(int j = 1;j <= n;j++) {
        for(int i = 1;i <= m;i++) {
            a[i][j] = max({a[i][j-1],a[i-1][j-1],a[i+1][j-1]}) + a[i][j];
        }
    }
    for(int i = 1;i <= m;i++) {
        ans = max(ans,a[i][n]); 
    }
    cout << ans;
    return 0;
}