#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];


ll cntcm(ll k)
{
    ll cnt = 0;
    for(int i = 1;i <= sqrt(k);i++) {
        if(k % i == 0) {
            cnt++;
            if(k / i != i) cnt++;
        }
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
    ll tmp = __gcd(x,y);
    cout << cntcm(tmp);
    return 0;
}