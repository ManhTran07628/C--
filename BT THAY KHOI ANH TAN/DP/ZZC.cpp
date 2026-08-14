#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
bool dp[2005][2005];
int n,q;
string s;

void palind(int l,int r) // l-1 | r+1
{
    while(l >= 1 && r <= n) {
        if(dp[l+1][r-1] && s[l] == s[r]) dp[l][r] = 1; 
        l--;
        r++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> s;
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        dp[i][i] = 1;
        if(s[i] == s[i+1]) dp[i][i+1] = 1;
    }
    for(int i = 2;i <= n;i++) {
        palind(i-1,i+1);
        palind(i-1,i+2);
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << (dp[l][r] ? "YES" : "NO") << '\n';
    }
    return 0;
}