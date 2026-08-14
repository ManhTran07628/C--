#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    sort(a+1,a+n+1);
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        ll fi = lower_bound(a+1,a+n+1,k-a[i]) - a;
        ll fi1 = upper_bound(a+1,a+n+1,k-a[i]) - a;
        cnt += fi1 - fi;
    }
    cout << cnt;
    return 0;
}