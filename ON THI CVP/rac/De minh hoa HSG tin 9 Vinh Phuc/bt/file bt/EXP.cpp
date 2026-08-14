#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "EXP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        if(n == 0 && m != 0 && m % 2 != 0) {
            cout << "NO" << '\n';
            continue;
        }
        else if(n != 0 && m == 0 && n % 2 != 0) {
            cout << "NO" << '\n';
            continue;
        }
        ll tong = n * 1 + m * 2;
        if(tong % 2 == 0) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}