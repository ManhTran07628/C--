#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "LINEGAME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    f[1][1] = a[1];
    f[1][2] = -a[1];
    ll ma = 0,maa = 0,mbb = 0;
    ma = max({ma,f[1][1],f[1][2]});
    for(int i = 2;i <= n;i++) {
        f[i][1] = max(maa+a[i],a[i]);
        f[i][2] = max(maa-a[i],-a[i]);
        ma = max({ma,f[i][1],f[i][2]});
        maa = max(f[i][1],maa);
        mbb = max(f[i][2],mbb);
        
    }
    cout << ma;
    //cout << f[n-1][1] << " " << f[n-1][2];
    return 0;
}
