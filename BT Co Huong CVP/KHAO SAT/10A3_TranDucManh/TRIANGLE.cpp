#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n,a[MM];


namespace subtask2
{
    void solve()
    {
        sort(a+1,a+n+1);
        int ans = MM+MM+MM; 
        for(int i = 1;i < n;i++) {
            int cnt = 0; 
            int f = a[i] + a[i+1]; 
            int last = n; 
            while(f <= a[last]) {
                last--;
                cnt++;
            }
            ans = min(ans,cnt+i-1);
        }
        cout << ans;
    }
}

namespace subtask3
{
    void solve()
    {
        sort(a+1,a+n+1);
        int ans = MM+MM+MM; 
        for(int i = 1;i < n;i++) {
            int pos = lower_bound(a+1,a+n+1,a[i]+a[i+1]) - a - 1;
            ans = min(ans,n - pos + i - 1);
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    if(n <= 100) subtask2::solve();
    else subtask3::solve();


    
    return 0;
}