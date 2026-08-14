#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
vector<ll> a;
ll max1 = -1e18;
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
    ll n;
    cin >> n;
    for(int i = 2;i <= sqrt(n);i++) {
        while(n % i == 0) {
            n /= i;
            a.push_back(i);
        }
    }
    if(n > 1) a.push_back(n);
    sort(a.begin(), a.end(), [](ll x, ll y) {
        return to_string(x) + to_string(y) > to_string(y) + to_string(x);
    });
    ll kq = 0;
    for (ll c : a) {
        ll temp = kq;
        ll dd = 1;
        while (c >= dd) {
            dd *= 10;
        }
        kq = kq * dd + c;
        max1 = max(max1,kq);
    }
    cout << max1;
    return 0;
}