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
    int n;
    cin >> n;
    int u1 = 1e9,v1 = 1e9,u2 = 0,v2 = 0;
    for(int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        u1 = min(u1,x);
        v1 = min(v1,y);
        u2 = max(u2,x);
        v2 = max(v2,y);
    }
    int ans = (u2-u1)*(v2-v1);
    cout << ans;
    return 0;
}