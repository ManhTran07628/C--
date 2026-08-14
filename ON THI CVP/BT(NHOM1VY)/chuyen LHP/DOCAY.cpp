#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    ll ans = 0;
    for(int i = 1;i < MAXN;i++) {
        ans += d[i]*(d[i]-1)/2;
    }
    cout << ans;
    return 0;
}