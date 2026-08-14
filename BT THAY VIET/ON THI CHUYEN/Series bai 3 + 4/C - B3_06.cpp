#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
map<ll,ll> b;
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
    ll n,x;
    cin >> n >> x;
    ll sum = 0,ans = 0;
    b[0] = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
        ans += b[sum-x];
        b[sum]++;
    }
    cout << ans;
    return 0;
}