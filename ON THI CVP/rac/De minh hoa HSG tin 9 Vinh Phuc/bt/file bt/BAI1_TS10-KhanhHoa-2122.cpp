#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHOKEO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,b,k,x,y;
    cin >> a >> b >> k >> x >> y;
    ll keocamcl = a * k - x;
    ll keochanhcl = b * k - y;
    cout << keocamcl - (keocamcl / 2) << " " << keochanhcl - (keochanhcl / 2);
    return 0;
}