#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
ll p[MAXN],check[MAXN];
vector<ll> v;

void pre(ll a,ll b)
{
    for(ll i = a;i <= b;i++) 
        for(ll j = 2;j*j <= 1e9;j++) {
            if(j*j > i) break;
            if(i % (j*j) == 0) {
                check[i-a] = 1;
                break;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll l,r;
    ll ans = 0;
    cin >> l >> r;
    pre(l,r);
    for(ll b = l;b <= r;b++) {
        for(ll a = l; a < b;a++) {
            if(check[a-l] || check[b-l] || __gcd(a,b) > 1) ans++;
        }
    }
    cout << ans;
    return 0;
}