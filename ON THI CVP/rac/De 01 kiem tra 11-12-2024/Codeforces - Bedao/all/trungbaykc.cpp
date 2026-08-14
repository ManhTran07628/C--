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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        ll pos = upper_bound(a+1,a+n+1,a[i]+k)-a;
        b[i] = pos;
        //cout << b[i] << ' ';
    }
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        ll tmp = 0;
        for(int j = b[i];j <= n;j++) {
            tmp = max(tmp,b[i]-i+b[j]-j);
        }
        ans = max(ans,tmp);
    }
    cout << ans;
    return 0;
}