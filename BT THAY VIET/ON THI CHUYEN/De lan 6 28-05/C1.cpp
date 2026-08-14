#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],ps[MAXN],mini[MAXN];
int n,k;
map<int,int> dem;

void trau()
{
    vector<int> divs;
    for(int i = k;i <= n;i++) {
        if(i % k == 0) divs.push_back(i);
    }
    int ans = 0;
    for(int length:divs) {
        int i = 1,j = 1,sum = 0;
        while(i <= n && j <= n) {
            if(j-i+1 > length) {
                ans = max(ans,sum);
                sum -= a[i];
                i++;
            }
            sum += a[j];
            j++;
        }
        ans = max(ans,sum);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    for(int i = 0;i <= n;i++) mini[i] = 1e18;
    // trau();
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,ps[i]-mini[i%k]);
        mini[i%k] = min(mini[i%k],ps[i]);
    }
    cout << ans;
    return 0;
}