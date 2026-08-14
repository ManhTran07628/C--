#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m,h[MM];
vector<int> adj[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    h[1] = 0;
    for(int i = 2;i <= n;i++) {
        vector<int> vec;
        for(auto v:adj[i]) {
            if(v > i) continue;
            vec.push_back(h[v]);
        }

        vec.push_back(-1);
        vec.push_back(1e9);

        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        int mex = 0;

        for(int j = 0;j < vec.size();j++) {
            if(vec[j] + 1 != vec[j + 1]) {
                mex = vec[j] + 1;
                break;
            }
        }
        h[i] = mex;
    }
    for(int i = 1;i <= n;i++) cout << h[i] << ' ';
    return 0;
}