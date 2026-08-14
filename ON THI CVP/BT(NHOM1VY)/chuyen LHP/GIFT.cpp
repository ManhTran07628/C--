#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e4+7;
ll a[MAXN];
ll dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll s = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = s/2;j >= a[i];j--) {
            dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout << abs(s-2*dp[s/2]);
    return 0;   
}