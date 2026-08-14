#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
ll f1[MAXN],f2[MAXN],a[MAXN],s[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= k;i++) cin >> s[i];
    fill(f1,f1+MAXN,-1e18);
    fill(f2,f2+MAXN,-1e18);
    f1[1] = a[1];
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i-s[j] >= 1) {
                f1[i] = max(f1[i],f1[i-s[j]]+a[i]);
            }
        }
    }
    for(int i = 1;i <= n;i++)  f1[i] = max(f1[i],f1[i-1]);
    f2[n] = a[n];
    for(int i = n-1;i >= 1;i--) {
        for(int j = 1;j <= k;j++) {
            if(i+s[j] <= n) {
                f2[i] = max(f2[i],f2[i+s[j]]+a[i]);
            }
        }
    }
    for(int i = n;i >= 1;i--) f2[i] = max(f2[i+1],f2[i]);
    ll ans = a[1]+a[n];
    for(int i = 0;i <= n;i++) {
        ans = max(ans,f1[i]+f2[i+1]);
    }
    cout << ans;
    return 0;
}