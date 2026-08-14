#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],dp[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "game"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    // ll n,k;
    // cin >> n >> k;
    // for(int i = 1;i <= n;i++) {
    //     cin >> a[i];
    // }
    // dp[1] = 0;
    // for(int i = 2;i <= n;i++) {
    //     dp[i] = 1e9;
    //     for(int j = 1;j <= k;j++) {
    //         if(i-j >= 1) {
    //             dp[i] = min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
    //         }
    //     }
    // }
    // cout << dp[n];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	f[1]=0;
	for(int i=2;i<=n;i++) {
        f[i] = 1e9;
		for(int j=1;j<=k;j++)
			if(i-j>0)
				f[i]=min(f[i],f[i-j]+abs(a[i]-a[i-j]));
    }
    cout << f[n];
    return 0;
}