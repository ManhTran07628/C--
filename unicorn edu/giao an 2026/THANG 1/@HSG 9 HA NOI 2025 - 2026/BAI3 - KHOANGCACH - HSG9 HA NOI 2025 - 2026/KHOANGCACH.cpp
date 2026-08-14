#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5 + 7;
string s;
int q,ps[MM][27],dist[500][500];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0;i < 26;i++) 
        for(int j = 0;j < 26;j++) 
            dist[i][j] = oo;

    for(int i = 0;i < 26;i++) {
        dist[i][i] = 0;
        for(int j = 0;j < 26;j++) {
            int l = (i + 26) % 26;
            int r = i + j;
            dist[l][r % 26] = min(dist[l][r % 26],abs(r - l));
            dist[r % 26][l] = min(dist[r % 26][l],abs(r - l));
        }
    }

    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        for(int j = 'a';j <= 'z';j++) {
            ps[i][j - 'a'] = ps[i-1][j - 'a'];
        }
        ps[i][s[i] - 'a']++;
    }
    cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        map<char,int> mp;
        for(int i = 'a';i <= 'z';i++) {
            if(ps[r][i - 'a'] - ps[l-1][i - 'a'] > 0) {
                mp[i - 'a'] += ps[r][i - 'a'] - ps[l-1][i - 'a'];
                // cout << (char) i << ' ' << ps[r][i - 'a'] - ps[l-1][i - 'a'] << '\n';
            }
        }

        int res = 0;
        for(auto x:mp) {
            for(auto y:mp) {
                // cout << (char) 'a' + x.fi << ' ' << (char) 'a' + y.fi << ' ' << dist[x.fi][y.fi] << '\n';
                res = max(res,dist[x.fi][y.fi]);
            }
        }        
        cout << res << '\n';
    }
    return 0;
}