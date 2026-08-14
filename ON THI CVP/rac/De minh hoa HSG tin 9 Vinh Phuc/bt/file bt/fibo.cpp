#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
ll tmp = 1e9 + 7;
ll n1 = 1e5;
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
    a[0] = 1;
    a[1] = 1;
    for(int i = 2;i <= n1;i++) {
        a[i] = (a[i-1] % tmp + a[i-2] % tmp) % tmp;
    }
    ll q;
    cin >> q;
    while(q--) {
        ll n;
        cin >> n;
        cout << a[n-1] << '\n';
    }
    return 0;
}