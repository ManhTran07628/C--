#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],d[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int i = 1,j = 1,ans = 0,diff = 0,cnt = 1;
    while(i <= n && j <= n) {
        d[a[j]]++;
        if(d[a[j]] == 1) diff++;
        if(diff > k) {
            while(diff > k) {
                d[a[i]]--;
                if(d[a[i]] == 0) diff--;
                i++;
            }
        }
        ans += j-i+1;
        j++;
    }
    cout << ans;
    return 0;
}