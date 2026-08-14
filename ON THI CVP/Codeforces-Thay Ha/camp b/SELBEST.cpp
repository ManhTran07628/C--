#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    ll t,n,a,b,c;
    cin >> t >> n >> a >> b >> c;
    ll x = min({a,b,c});
    if(t == 1) {
        cout << n-x;
    }
    else cout << max(0,a+b+c-n-n);
    return 0;
}