#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],x[MAXN],prefix1[MAXN],prefix2[MAXN];
int n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int t = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
        prefix1[i] = prefix1[i-1] + a[i];
        prefix2[i] = prefix2[i-1] + x[i]*a[i];
    }
    int ans = 1e18;
    for(int i = 1;i <= n;i++) {// so buoc di chuyen tu vi tri 1 -> vi tri < i
        int left = x[i]*prefix1[i]-prefix2[i]; 
        int right = (prefix2[n]-prefix2[i])-x[i]*(prefix1[n]-prefix1[i]);
        // so buoc di chuyen tu vi tri i+1 -> r
        ans = min(ans,left+right);
    }
    cout << ans;
    return 0;
}