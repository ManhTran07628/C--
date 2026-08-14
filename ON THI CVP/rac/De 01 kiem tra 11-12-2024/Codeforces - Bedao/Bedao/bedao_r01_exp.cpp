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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        unsigned ll a,b,a1,b1;
        cin >> a >> b >> a1 >> b1;
        unsigned ll x = a*pow(10,b);
        unsigned ll y = a1*pow(10,b1);
        if(x > y) cout << "X > Y";
        else if(x < y) cout << "X < Y";
        else cout << "X = Y";
        cout << '\n';
    }
    return 0;
}