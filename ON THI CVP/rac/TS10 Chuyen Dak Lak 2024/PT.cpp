#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;

ll prime(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++)
        if(k % i == 0) return 0;
    return 1;
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
    ll n,cnt = 0;
    cin >> n;
    while(n--) {
        ll a,b;
        cin >> a >> b;
        ll ans = -b/a;
        if(prime(ans) && ans * a + b == 0) cnt++;
    }
    cout << cnt;
    return 0;
}