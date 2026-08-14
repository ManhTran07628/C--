#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],c[N],d[N][4];

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
        cin >> a[i] >> b[i] >> c[i];
    }
    d[1][1] = a[1];
    d[1][2] = b[1];
    d[1][3] = c[1];
    for(int i = 2;i <= n;i++) { //1 - A, 2 - B,3 - C
        d[i][1] = max(d[i-1][2],d[i-1][3]) + a[i];
        d[i][2] = max(d[i-1][1],d[i-1][3]) + b[i];
        d[i][3] = max(d[i-1][1],d[i-1][2]) + c[i];
    }
    cout << max({d[n][1],d[n][2],d[n][3]});
    return 0;
}


