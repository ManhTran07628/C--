#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+1;
ll a[N][N];
vector<pair<ll,ll>> b;
ll m,n,u,v;



ll quaylui(ll i,ll j)
{
    if((i == 1 || j == 1) && (i <= {
        inkq();
        return;
    }
    if(a[i][j] == 1) return;
    quaylui(i+1,j);
    quaylui(i-1,j);
    quaylui()
}





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
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }

    return 0;
}