#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "parity"
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
        ll so = 0;
        while(n > 0) {
            if(n % 2 == 1) so++;
            n /= 2;
        }
        if(so % 2 == 0) cout << "even" << '\n';
        else cout << "odd" << '\n';
    }
    return 0;
}