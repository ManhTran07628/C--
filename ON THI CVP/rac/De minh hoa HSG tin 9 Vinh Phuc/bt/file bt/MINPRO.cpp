#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "minpro"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        ll n1 = n;
        ll a1 = a - min(a-x,n);
        n = n - min(a-x,n);
        ll b1 = b - min(b-y,n);



        ll b2 = b - min(b-y,n1);
        n1 = n1 - min(b-y,n1);
        ll a2 = a - min(a-x,n1);
        cout << min(a1*b1,a2*b2) << '\n';
    }
    return 0;
}