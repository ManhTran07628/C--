#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
long double a[N];

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
    ll n,l;
    cin >> n >> l;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    long double ans = a[1] - 0;
    for(int i = 2;i <= n;i++) {
        long double x = (a[i]-a[i-1])/2;
        ans = max(ans,x);
    }
    ans = max(ans,l-a[n]);
    cout << fixed << setprecision(10) << ans;
    return 0;
}