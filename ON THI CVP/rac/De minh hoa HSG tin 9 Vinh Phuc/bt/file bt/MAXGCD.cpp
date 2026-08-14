#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll tmp = 1e9 + 7;
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
    ll a1,b1;
    cin >> a1 >> b1;
    ll n = min(a1,b1);
    ll kq = 1;
    for(int i = 1;i <= n;i++) {
        kq = (kq * i) % tmp;
    }
    cout << kq % tmp;
    return 0;
}
