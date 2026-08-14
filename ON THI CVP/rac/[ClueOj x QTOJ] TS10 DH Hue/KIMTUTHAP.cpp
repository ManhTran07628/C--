#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h;
    cin >> h;
    int ans = 0;
    for(int i = 1;i <= h;i++) 
        ans += (h-i+1)*i;
    cout << ans;
    return 0;
}