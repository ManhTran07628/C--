#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
vector<int> a;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,mm,ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int ai;
        cin >> ai; a.push_back(ai);
        mm = max(mm,ai);
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < n;i++) {
        for(int j = a[i]*2;j <= mm*2;j+=a[i]) {
            auto pos = lower_bound(a.begin(),a.end(),j)-1;
            ans = max(ans,*pos%a[i]);
        }
    }
    cout << ans;
    return 0;
}