#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n,u2,v2,k,ans = 0;
    cin >> m >> n >> u2 >> v2 >> k;
    for(int u1 = 1;u1 <= m;u1++) {
        for(int v1 = 1;v1 <= n;v1++) {
            ans += ((abs(u1-u2)+abs(v1-v2)) <= k);
        }
    }
    cout << ans-1;
    return 0;
}