#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("AVG.inp","r",stdin);
    freopen("AVG.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll cnt = 0,sum = 0;
    b[0] = 1;
    for(int i = 1;i <= n;i++) {
        sum += a[i];
        cnt += b[sum-i*k];
        b[sum-i*k]++;
    }
    cout << cnt;
    return 0;
}
