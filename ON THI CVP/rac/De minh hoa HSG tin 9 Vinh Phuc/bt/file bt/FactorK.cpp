#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "FactorK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        for(int i = 2;i <= sqrt(n);i++) {
            while(n % i == 0) {
                a.push_back(i);
                n /= i;
            }
        }
        if(n > 1) a.push_back(n);
        if(a.size() < k) {
            cout << -1 << '\n';
        }
        else {
            cout << a[k-1] << '\n';
        }
        a.clear();
    }
    return 0;
}