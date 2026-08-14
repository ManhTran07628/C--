#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 3e6+7;
ll a[N];
unordered_map<ll,ll> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        m[a[i]]++;
        ans = max(ans,max(m[a[i]+1],m[a[i]-1])+m[a[i]]);
    }
    cout << ans;
    return 0;
}