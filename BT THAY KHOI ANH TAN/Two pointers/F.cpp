#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN],h[MAXN];
int n,m;

void solve()
{
    int i = 1,j = 1;
    int ans = 0,value = 0;
    while(i <= n && j <= n) {
        if(h[j-1] % h[j] == 0) {
            value += a[j];
            while(value > m) {
                value -= a[i];
                i++;
            }   
            ans = max(ans,j-i+1);
        }
        else {
            value = a[j];
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> h[i];
    solve();
    return 0;
}