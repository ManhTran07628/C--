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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll max1 = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        max1 = max(max1,a[i]);
    }
    ll p,ans = 0;
    cin >> p;
    for(int i = 1;i <= n;i++) {
        ans += (max1-a[i]);
    }
    cout << ans * p;
    return 0;
}