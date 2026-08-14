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
    #define taskname "DGROUP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,k;
    cin >> n >> m >> k;
    ll cntt = min(n/2,m);
    n -= cntt*2;
    m -= cntt;
    if(n+m == k) {
        cout << cntt;
        return 0;
    }
    k = k - n - m;
    while(k > 0) {
        cntt--;
        k -= 3;
    }
    cout << cntt;
    return 0;
}