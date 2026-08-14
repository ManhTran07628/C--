#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<int,int> a[MAXN];
int x[MAXN],y[MAXN];
int n,k;

int result(int p)
{
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(p-k <= y[i] && y[i] <= p+k) {
            ans += x[i];
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        x[i] = a[i].fi;
        y[i] = a[i].se;
        y[i] += y[i-1];
    }
    int i = 1,pos = x[1]+k,ans = 0;
    while(i <= n) {
        pos = x[i]+k;
        int l = lower_bound(x+1,x+n+1,pos-k)-x;
        int r = upper_bound(x+1,x+n+1,pos+k)-x-1;
        ans = max(ans,y[r]-y[l-1]);
        i++;
    }
    cout << ans;
    return 0;
}