#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N],sl[N];
ll tmp = 1e9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CPL"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(ll i = 1;i <= sqrt(tmp);i++) {
        if(i % 2 != 0) {
            a[i] = a[i-1] + i*i;
            b[i] = b[i-1] + 1;
        }
        else {
            a[i] = a[i-1] + a[i];
            b[i] += b[i-1];
        }
    }
    ll n1 = floor(sqrt(n));
    cout << b[n1] << '\n' << a[n1];
    return 0;
}