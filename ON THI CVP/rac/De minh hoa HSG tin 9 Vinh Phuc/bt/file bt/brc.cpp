#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a,b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cut"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    cout<< (m/__gcd(n,m)-1) * __gcd(n,m);
    // gcd(n,m) la so phan banh dc chia deu k du
    // m / gcd(n,m) - 1 la so thao tac thuc te de chia banh
    // m/gcd(n,m)-1 * gcd(n,m) la so lan thuc hien chia banh deu
    return 0;
}

