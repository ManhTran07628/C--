#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Friend"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,b;
    cin >> n >> b;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        ll vtd = lower_bound(a+1,a+n+1,b-a[i]) - a;
        ll vtc = upper_bound(a+1,a+n+1,b-a[i]) - a;
        if(vtd > i)
            dem = dem + vtc - vtd;
    }
    cout << dem;
    return 0;
}
