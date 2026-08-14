#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],d[N];

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
        cin >> a[i];
    }
    d[1] = 0;
    d[2] = abs(a[2]-a[1]);
    for(int i = 3;i <= n;i++) {
        d[i] = min(d[i-1] + abs(a[i]-a[i-1]),d[i-2] + abs(a[i]-a[i-2]));
    }
    cout << d[n];
    return 0;
}
