#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];
int n;

bool check(int k)
{
    int sum = 0;
    for(int i = 1;i <= n;i++) {
        if(sum+a[i] == k) sum = 0;
        else if(sum+a[i]<k) sum+=a[i];
        else return 0;
    }
    return 1;
}

void solve()
{
    int dmax = 0,sum = 0;
    for(int i = 1;i <= n;i++) {
        dmax = max(dmax,a[i]);
        sum += a[i];
    }
    int ans = 0;
    for(int i = 1;i*i <= sum;i++) {
        if(sum%i==0) {
            if(i >= dmax && check(i)) ans++;
            if(sum/i!=i&&sum/i>=dmax&&check(sum/i)) ans++;
        }
    }

    cout << ans << '\n';

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];
        solve();
    }
    return 0;
}