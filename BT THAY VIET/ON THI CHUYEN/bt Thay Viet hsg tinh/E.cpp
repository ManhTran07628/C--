#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

bool check(ll x1,ll x2,ll x3)
{
    map<ll,ll> b;
    while(x1 > 0) {
        b[x1%10]++;
        x1 /= 10;
    }
    while(x2 > 0) {
        b[x2%10]++;
        x2 /= 10;
    }
    while(x3 > 0) {
        b[x3%10]++;
        x3 /= 10;
    }
    for(int i = 1;i <= 9;i++) {
        if(b[i] != 1) return 0;
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
    for(int x1 = 100;x1 <= 333;x1++) {
        ll x2 = x1*2;
        ll x3 = x1*3;
        if(check(x1,x2,x3)) {
            cout << x1 << " " << x2 << " " << x3 << '\n';
        }
    }
    return 0;
}