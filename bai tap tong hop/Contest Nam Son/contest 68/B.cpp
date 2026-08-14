#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+7;
ll a[N],f[N][3];

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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    f[1][1] = max(0ll,a[1]);
    f[2][1] = max(0ll,a[2]);
    f[2][2] = max({f[1][1]+a[2],a[1],a[2],0ll});
    for(int i = 3;i <= n;i++) {
        f[i][1] = max(max(f[i-1][2],f[i-1][1]),max(f[i-2][2],f[i-2][1])+max(0ll,a[i]));
        f[i][2] = max(f[i-1][1]+max(0ll,a[i]),max(f[i-2][1],f[i-2][2])+max(0ll,a[i]));
    }
    cout << max({f[n][0],f[n][1],f[n][2]});
    return 0;
}