#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int M = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1;i < n;i++) {
        ans = (ans*10+1)%M;
    }
    cout << ans;
    return 0;
}