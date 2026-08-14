#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,k = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a,b;
        if(n == 3) {
            a = 2,b = 3;
        }
        else {
            if(n % 2 == 1) n--;
            a = n/2;b = n;
        }
        cout << "Case "<<k<<": "<<a<<" "<<b << '\n';
        k++;
    }
    return 0;
}