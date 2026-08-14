#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,q,a[MM],vis[MM];
map<int,int> cnt,vi;
vector<vector<int>> ps;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] <= n) cnt[ a[i] ]++;
    }
    int sz = 0;
    for(int i = 1;i <= n;i++) {
        if(!vi[ a[i] ] && cnt[ a[i] ] >= a[i]) {
            vis[sz++] = a[i];
            vi[ a[i] ] = 1;
            vector<int> v;
            v.resize(n + 7);
            for(int j = 1;j <= n;j++) {
                v[j] = v[j-1] + (a[i] == a[j]);
            }
            ps.push_back(v);
        }
    }

    while(q--) {
        int l,r; cin >> l >> r;
        int res = 0;
        for(int i = 0;i < sz;i++) {
            if(ps[i][r] - ps[i][l-1] == vis[i]) {
                res++;
                // cout << ps[i][r] - ps[i][l-1] << ' ' << vis[i] << '\n';
            }
        }
        cout << res << '\n';
    }
    return 0;
}