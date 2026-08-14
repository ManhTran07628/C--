#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N],s[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= k;i++) {
        cin >> s[i];
    }
    fill(l,l+N,-1e9);
    fill(r,r+N,-1e9);
    sort(s+1,s+k+1);
    l[1] = a[1];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i - s[j] >= 1) {
                l[i] = max(l[i],l[i-s[j]] + a[i]);
            }
        }
    }
    r[n] = a[n];
    for(int i = n;i >= 1;i--) {
        for(int j = 1;j <= k;j++) {
            if(i + s[j] <= n) {
                r[i] = max(r[i],r[i+s[j]] + a[i]);
            }
        }
    }
    for(int i=2;i<=n;i++) l[i]=max(l[i],l[i-1]);
	for(int i=n-1;i>0;i--) r[i]=max(r[i],r[i+1]);
    ll ans = -1e9;
    for(int i = 1;i < n;i++) {
        ans = max(ans,l[i]+r[i+1]);
    }
    cout << ans;
    return 0;
}