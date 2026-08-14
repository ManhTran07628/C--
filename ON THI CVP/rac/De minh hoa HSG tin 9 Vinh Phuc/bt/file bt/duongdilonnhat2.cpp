#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[1001][1001],f[1001][1001];

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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            f[i][j] = max(f[i-1][j] + a[i][j],f[i][j-1] + a[i][j]);
        }
    }
    cout << f[n][n];
    return 0;
}