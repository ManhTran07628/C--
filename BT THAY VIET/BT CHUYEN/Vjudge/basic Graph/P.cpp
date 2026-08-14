#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 105+7;
vector<int> adj[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int x;
            cin >> x;
            if(x) {
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        cout << adj[i].size() << ' ';
        for(auto x:adj[i]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}