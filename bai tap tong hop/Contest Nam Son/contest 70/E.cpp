#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll p[MAXN],a[MAXN];
map<ll,ll> lt;
ll dem2 = 0,dem5 = 0;
void min_prime()
{
    for(int i = 2;i * i < MAXN;i++)
        if(p[i] == 0)
            for(int j = i*2;j < MAXN;j+=i)
                if(p[j] == 0) p[j] = i;
    for(int i = 2;i < MAXN;i++) if(p[i] == 0) p[i] = i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_prime();
    p[1] = 1;
    ll ans = 1;
    for(int i = 1;i <= MAXN-6;i++) {
        ll k = i;
        map<ll,ll> ltl;
        while(k > 1) {
            ltl[p[k]]++;
            if(p[k] == 2) dem2++;
            if(p[k] == 5) dem5++;
            if(ltl[p[k]] > lt[p[k]]) {
                if(p[k] == 2 && dem5 > 0) {
                    dem5--;
                    if(ans % 5 != 0) ans *= 10;
                    ans /= 5;
                }
                else if(p[k] == 5 && dem2 > 0) {
                    dem2--;
                    if(ans % 2 != 0) ans *= 10;
                    ans /= 2;
                }
                else ans *= p[k];
                lt[p[k]] = ltl[p[k]];
            }
            k /= p[k];
        }
        ans %= 10000;
        a[i] = ans % 10;
    }
    int x;
    while(cin >> x) cout << a[x] << '\n';
    return 0;
}