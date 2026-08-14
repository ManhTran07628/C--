#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int n,m,L[MM],R[MM],ans[MM];
struct Edge{int u,v; ll w;};
vector<Edge> edges;
struct Query{int s,t; ll steps;};
vector<Query> queries;
vector<int> mid[MM];


void solve()
{
    while(1) {
        bool ok = 1;
        for(int i = 1;i <= m;i++) {
            if(L[i] > R[i]) continue;
            ok = 0;
            mid[ (L[i] + R[i]) / 2 ].push_back(i);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    edges.resize(n + 7);
    for(int i = 1;i < n;i++) 
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    queries.resize(n + 7);
    for(int i = 1;i <= m;i++) {
        cin >> queries[i].s >> queries[i].t >> queries[i].steps;
        L[i] = 0, R[i] = n, ans[i] = -1;
    }   
    return 0;   
}