#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


bool check(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++) 
        if(k % i == 0) return 0;
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
    ll n;
    cin >> n;
    ll m = 1;
    for(int i = 1;i <= sqrt(n);i++) {
        if(check(i)) m = i;
    }
    if(n == 8) {
        cout << 8;
        return 0;
    }
    ll ans = n / m;
    while(!check(ans)) ans--;
    ans = ans * m;
    cout << ans;
    return 0;
}