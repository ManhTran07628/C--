#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ans += abs(a[i]-x);
    }
    cout << ans;
    return 0;
}