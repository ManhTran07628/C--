#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "AMSUM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    ll maxx = -1e9,minx = 1e9,maxy = -1e9,miny = 1e9;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        maxx = max(maxx,a1);
        minx = min(minx,a1);
    }
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        maxy = max(maxy,a1);
        miny = min(miny,a1);
    }
    cout << (maxx-minx)*(maxy-miny);
    return 0;
}