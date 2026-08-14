#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int d = 2024;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    if(n % 2 == 0) ans = (((n/2)%2024)*(n-1)%2024)%2024;
    else ans = (((n-1)/2)%2024*(n%2024))%2024;
    cout << ans%d;
    return 0;
}