#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll a1,b;
    cin >> a1 >> b;
    ll min1 = min(a1,b);
    ll max1 = max(a1,b);
    cout << max((min1+1) / 2,(max1+1) / 2) << ' ' << min(min1,max1);
    return 0;
}
