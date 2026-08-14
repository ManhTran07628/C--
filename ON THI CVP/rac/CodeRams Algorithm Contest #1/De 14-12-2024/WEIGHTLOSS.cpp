#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll n,k;

ll check(ll d)
{
    ll cnt = 0;
    for(int i = 1;i <= n-1;i++) {
        cnt += ((a[i+1]-a[i]-1) / d);
    }
    return cnt <= k;
}


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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll L = 0,R = 1e9,ans = n;
    while(L <= R) {
        ll mid = (L+R)/2;
        if(check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}