#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tiling2"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    f[1] = 1;
    f[2] = 3;
    for(int i = 3;i <= n;i++) {
        f[i] = f[i-1]+2*f[i-2];
    }
    cout << f[n];
    return 0;
}