#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2500+7;
int n,m,parent[MM],d[MM];
vector<int> NegCycle;
struct Node{
    int u,v,w;
};
vector<Node> E;

void bellman_ford()
{
    for(int i = 1;i <= n;i++) {
        for(auto e:E) {
            int u = e.u, v = e.v,w = e.w;
            if(d[u] != oo && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
}

bool FindNegativeCycle()
{
    int start = -1;
    for(auto e:E) {
        int u = e.u, v = e.v,w = e.w;
        if(d[u] != oo && d[v] > d[u] + w) {
            parent[v] = u;
            start = v;
            break;
        }
    }
    if(start == -1) return 0;
    int u = start;
    for(int i = 1;i <= n;i++) {
        u = parent[u];
    }
    int v = parent[u];
    NegCycle.push_back(u);
    while(v != u) {
        NegCycle.push_back(v);
        v = parent[v];
    }
    NegCycle.push_back(u);
    reverse(NegCycle.begin(),NegCycle.end());
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        E.push_back({a,b,c});
    }
    bellman_ford();
    if(FindNegativeCycle()) {
        cout << "YES" << '\n';
        for(auto i:NegCycle) cout << i << ' ';
    }
    else cout << "NO";
    return 0;
}