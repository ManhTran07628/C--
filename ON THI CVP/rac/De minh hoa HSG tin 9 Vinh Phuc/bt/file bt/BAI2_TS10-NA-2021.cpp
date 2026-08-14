#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a1[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHIAHET"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,b,x,y;
    cin >> a >> b >> x >> y;
    if(a % x != 0) {
        a += (x % a);
    }
    ll tong1 = (b-a)/x+1;
    ll tong2 = (b-a)/y+1;
    cout << tong1 + tong2 - b / (x*y);
    return 0;
}
