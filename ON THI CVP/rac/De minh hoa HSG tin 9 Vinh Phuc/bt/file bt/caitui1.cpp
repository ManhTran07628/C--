#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+7;
ll a[N],b[N],d[N][100],max1 = -1e18;

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
    ll n,w;
    cin >> n >> w;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= w;j++) {
            d[i][j] = d[i-1][j];
            if(j >= a[i]) {
                d[i][j] = max(d[i][j],d[i-1][j-a[i]] + b[i]);
            }
            max1 = max(max1,d[i][j]);
        }
    }
    cout << max1;
    return 0;
}



