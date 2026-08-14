#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
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
    ll n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll ans = 1e9;
    for(int i = 1;i <= n;i++) {
        ll lo = lower_bound(b+i,b+n+1,s+b[i-1]) - b;
        //cout << i-1 << " " << lo << '\n';
            ans = min(ans,lo-i);
    }
    cout << ans;
    return 0;
}