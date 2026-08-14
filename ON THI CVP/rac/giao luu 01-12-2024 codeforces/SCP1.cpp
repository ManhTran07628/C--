#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

ll cntnums(ll k) 
{
    ll cnt = 0;
    while(k > 0){
        cnt++;
        k /= 10;
    }
    return cnt;
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
    ll x,y; 
    cin >> x >> y;
    ll ans = 0;
    for(ll i = x;i <= y;i++) {
        ans += cntnums(i*i);
    }
    cout << ans;
    return 0;
}