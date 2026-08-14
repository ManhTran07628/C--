#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sub"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll min1 = 1e9;
    for(int i = 1;i <= n;i++) {
        ll vtd = lower_bound(b+1,b+n+1,s+b[i-1]) - b;
        if(vtd != n+1) {
            //cout << b[vtd] << " " << b[i-1] << '\n';
            min1 = min(min1,vtd-i+1);
        }
    }
    cout << min1;
    return 0;
}