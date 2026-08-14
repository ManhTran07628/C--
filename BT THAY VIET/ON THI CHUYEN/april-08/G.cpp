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
    ll n,m,k;
    cin >> n >> m >> k;
    ll ans = 0;
    if(n == m && m == 1) {
        cout << 0;
        return 0;
    }
    if(k >= n-1 && k >= m-1) {
        if(n == m) cout << 1;
        else cout << 2;
        return 0;
    }
    if(n == m) {
        n--;
        ans = n/k;
        if(n % k != 0)ans++;
    }
    else {
        if(n < m) swap(n,m);
        m--;
        ans = m/k;
        if(m%k!=0)ans++;
        n-=m+1;
        ans+=n/k;
        if(n%k!=0)ans++;
    }
    cout << ans;
    return 0;
}