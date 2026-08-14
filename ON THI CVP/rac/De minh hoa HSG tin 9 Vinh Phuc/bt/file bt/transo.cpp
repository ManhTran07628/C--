#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a,b,c,kq = 1;
ll dq(ll a,ll b)
{
    if(b == 0) return 0;
    ll x = dq(a,b/2);
    if(b % 2 == 0) return 2 * x % c;
    else return (2 * x + a) % c;
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
    cin >> a >> b >> c;
    kq = dq(a,b);
    cout << kq;
    return 0;
}   