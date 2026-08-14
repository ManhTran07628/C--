#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,dp[MM];
string s;
int mp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    string t;
    s = ' ' + s;
    for(int i = 'a';i <= 'a' + m - 1;i++) {
        char c = i; t.push_back(c);
    }

    ll ans = oo;
    ll res = 0;
    for(int i = 0;i < m;i++) mp[ t[i] ] = i;
    for(int i = 1;i <= n;i++) res += abs(mp[ s[i] ] - mp[ s[i-1] ]);
    ans = min(ans,res);


    while(next_permutation(t.begin(),t.end())) {
        for(int i = 0;i < m;i++) mp[ t[i] ] = i;
        ll res = 0;
        for(int i = 2;i <= n;i++) res += abs(mp[ s[i] ] - mp[ s[i-1] ]);
        ans = min(ans,res);
    }
    cout << ans;
    return 0;
}