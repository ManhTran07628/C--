#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PrimeFactors"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n; 
        ll tmp = n; 
        for(int i = 2;i <= sqrt(tmp);i++) {
            while(n % i == 0) {
                a[i]++;
                n /= i;
            }
        }
        if(n > 1) a[n]++;
        for(auto c:a) {
            cout << c.first << " " << c.second << " ";
        }
        cout << '\n';
        a.clear();
    }
    return 0;
}