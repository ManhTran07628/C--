#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    int ans = sum*sum;
    cout << ans;
    return 0;
}