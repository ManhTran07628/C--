#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

ll check(ll k)
{
    while(k > 0) {
        ll tmp = k % 10;
        if(a[tmp] == 1) return 0;
        k /= 10;
    }
    return 1;
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
    ll p,s;
    cin >> p >> s;
    while(s > 0) {
        a[s%10] = 1;
        s /= 10;
    }
    while(check(p) != 1) {
        p--;
        if(p <= 0) {
            cout << -1;
            return 0;
        }
    }
    
    cout << p;
    return 0;
}