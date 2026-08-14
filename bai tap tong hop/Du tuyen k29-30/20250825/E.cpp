#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 500+7;
ll dp[MM][MM],n,vis[MM][MM],f[MM][MM];
string s;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        f[i][i] = 1;
        f[i][1] = 1;
    }
    
    return 0;
}