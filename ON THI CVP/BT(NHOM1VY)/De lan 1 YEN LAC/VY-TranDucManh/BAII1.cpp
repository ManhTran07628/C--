#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,int> lt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll A,B;
    cin >> A >> B;
    ll n = __gcd(A,B);
    ll ans = 0;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            ans++;
            if(n / i != i) ans++;
        }
    }cout << ans;
    return 0;
}