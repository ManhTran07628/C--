#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int t; 
int vis[3][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int n; cin >> n;
        string a[3];
        for(int i = 1;i <= 2;i++) {
            a[i].push_back(' ');
            string s; cin >> s;
            for(auto x:s) a[i].push_back(x);
        }
        for(int i = 0;i <= n+1;i++) vis[1][i] = 0;
        int chess = 0;
        for(int i = 1;i <= n;i++) {
            if(a[2][i] == '0') continue;
            if(a[2][i] == '1' && a[1][i] == '0') {
                chess++;
                continue;
            }
            if(a[2][i] == '1' && a[1][i] == '1' && a[1][i-1] == '1' && !vis[1][i-1]) {
                chess++;
                vis[1][i-1] = 1;
                continue;
            }
            if(a[2][i] == '1' && a[1][i] == '1' && a[1][i+1] == '1' && !vis[1][i+1]) {
                chess++;
                vis[1][i+1] = 1;
                continue;
            }
            
        }
        cout << chess << '\n';
    }
    return 0;
}