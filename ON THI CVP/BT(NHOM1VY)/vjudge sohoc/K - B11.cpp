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
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll sum = 0;
        for(ll i = 1;i <= sqrt(n);i++) {
            if(n % i == 0) {
                sum += i;
                if(n / i != i) sum += n/i;
            }
        }
        cout << sum-n << '\n';
    }
    return 0;
}