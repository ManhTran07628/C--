#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = 1,sum = 0,ans = 0;
    while(i <= n && j <= n) {
        sum += a[j];    
        while(sum > k) {
            sum -= a[i];
            i++;
        }
        ans += j-i+1;
        j++;
    }
    cout << ans;
    return 0;
}