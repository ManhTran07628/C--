#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHIPHI"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,x;
    cin >> n >> x;
    ll ans = n/2;
    if(n % 2 != 0) 
        ans = n /2 + 1;
    cout << ans * x;
    return 0;
}