#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int h[MAXN],b[MAXN];
int n,k;



void solve()
{
    int i = 1,j = 1,trees = 0,ans = 0;
    while(i <= n && j <= n) {
        while(j-i+1 > k) {
            trees -= b[i];
            i++;
        }
        if(__gcd(h[j-1],h[j]) > 1) {
            trees += b[j];
            ans = max(ans,trees);
        }
        else {
            trees = b[j];
            i = j;
        }
        j++;
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    solve();
    return 0;
}