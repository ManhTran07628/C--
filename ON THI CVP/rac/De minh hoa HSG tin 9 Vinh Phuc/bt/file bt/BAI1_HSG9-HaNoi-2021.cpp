#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MAXPRO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a1,b,c,m;
    cin >> a1 >> b >> c >> m;
    if(a1 < 0) {
        a1 = ((a1 % m) + m) % m;
    }
    if(b < 0) {
        b = ((b % m) + m) % m;
    }
    if(c < 0) {
        c = ((c % m) + m) % m;
    }
    cout << a1 << " " << c;
    // ll th1 = (a1*b)%m;
    // ll th2 = (a1*c)%m;
    // ll th3 = (b*c)%m;
    // cout << max({th1,th2,th3});
    return 0;
}
