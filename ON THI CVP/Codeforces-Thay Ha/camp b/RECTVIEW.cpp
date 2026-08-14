#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    ll x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
    ll ans = (x2-x1)*(y2-y1) + (x4-x3)*(y4-y3);
    ll c = max(0ll,min(x2,x6) - max(x1,x5)) * max(0ll,min(y2,y6) - max(y1,y5));
    ll u = max(0ll,min(x6,x4) - max(x3,x5)) * max(0ll,min(y6,y4) - max(y3,y5));
    cout << ans - c - u;
    return 0;
}