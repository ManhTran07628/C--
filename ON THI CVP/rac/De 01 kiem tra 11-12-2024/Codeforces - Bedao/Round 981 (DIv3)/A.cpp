#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

void solve(ll n)
{
    ll x = 0,i = 1;
    while(abs(x) <= n) {
        if(i % 2 == 1) {
            x -= (2*i-1);
        }
        else x += (2*i-1);
        if (abs(x) > n) {
            break;
        }
        i++;
    }
    if(i % 2 == 0) cout << "Kosuke" << '\n';
    else cout << "Sakurako" << '\n';
}

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
    while(t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}