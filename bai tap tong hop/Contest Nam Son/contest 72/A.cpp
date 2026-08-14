#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e7+7;
int p[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        int ok = 1;
        for(ll i = 2;i*i <= n;i++) {
            if(n % i == 0) {
                ok = 0;
                break;
            }
        }
        if(ok || n == 1) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        int k1 = 1,k2 = 0;
        for(ll i = 2;i*i <= n;i++) {
            if(n % i == 0) {
                k2++;
                int cnt = 0;
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                }
                k1 *= (cnt+1);
            }
        }
        if(n > 1) {
            k1*=2;
            k2++;
        }
        cout << k1-2 << ' ' << k2 << '\n';
    }
    return 0;
}