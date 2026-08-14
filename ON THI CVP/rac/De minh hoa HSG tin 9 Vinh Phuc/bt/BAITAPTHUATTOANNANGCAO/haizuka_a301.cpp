#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll tmp = 1e9+7;

ll nhanando(ll a,ll b)
{
    
    if(b == 0) return 0;
    ll kq = nhanando(a,b/2) % tmp;


    if(b % 2 == 1) return ((kq+kq)%tmp+a%tmp)%tmp;
    else return (kq+kq)%tmp;
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
    ll a,b,c;
    cin >> a >> b >> c;
    ll kq = nhanando(a,b);
    c = c % tmp;
    kq = kq / c;
    cout << kq;
    return 0;
}