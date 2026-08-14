#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tiling1"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    a[1] = 1;
    a[2] = 2;
    ll tmp = 1e9 + 7;
    for(int i = 3;i <= n;i++) {
        a[i] = (a[i-1] + a[i-2])%tmp;
    }
    cout << a[n];
    return 0;
}