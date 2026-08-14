#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

bool prime_check(ll k)
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
    #define taskname "goldbach"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll k,c;
        cin >> k;
        c = 0;
        while(c < k) {
            if(prime_check(c) == 1 && prime_check(k) == 1) break;
            c++;
            k--;
        }
        cout << c << " " << k << '\n';
    }
    return 0;
}