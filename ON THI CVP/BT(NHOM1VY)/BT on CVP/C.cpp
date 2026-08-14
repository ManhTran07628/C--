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
    ll n,t;
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = 0;
    if(a[t] == 1) ans = 1;
    int i;
    for(i = 1;i <= n;i++) {
        if(t-i >= 1 && t+i <= n) {
            if(a[t-i] == 1 && a[t+i] == 1) ans+=2;
        }
        else break;
    }
    //cout << i;
    if(t <= n / 2) {
        t += i;
        while(t <= n) {
            if(a[t]) ans++;
            t++;
        }
    }
    else if(t > n/2) {
        t -= i;
        while(t >= 1) {
            if(a[t]) ans++;
            t--;
        }
    }
    cout << ans;
    return 0;
}