#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    ll n,m,k;
    cin >> n >> m >> k;
    ll t1 = n / k;
    ll t2 = m / k;
    if(n % k != 0) t1++;
    if(m % k != 0) t2++;
    cout << t1 * t2;
    return 0;
}