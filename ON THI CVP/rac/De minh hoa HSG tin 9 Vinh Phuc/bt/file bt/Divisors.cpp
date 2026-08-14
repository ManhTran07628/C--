#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Divisors"
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
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        ll temp;
        if(n == 1) temp = a[1];
        else temp = __gcd(a[1],a[2]);
        for(int i = 2;i < n;i++) {
            temp = __gcd(temp,a[i+1]);
        }
        ll so = 0;
        for(int i = 1;i <= sqrt(temp);i++) {
            if(temp % i == 0) {
                so++;
                if(temp / i != i) so++;
            }
        }
        cout << so << '\n';
    }
    return 0;
}