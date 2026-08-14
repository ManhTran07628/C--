#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5+7;
int parent[MM],sz[MM],d[MM];
pair<int,int> query[MM],edge[MM]; 
vector<int> ans;
int find_set(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i <= m;i++) cin >> edge[i].fi >> edge[i].se;
    for(int i = 1;i <= q;i++) {
        cin >> query[i].fi >> query[i].se;
        d[query[i].fi] = 1;
    }
    for(int i = 1;i <= m;i++) 
        if(!d[i]) {
            union_sets(edge[i].fi,edge[i].se);
        }
    for(int i = q;i >= 1;i--) {
        ans.push_back(sz[find_set(query[i].se)]);
        int u = edge[query[i].fi].fi,v = edge[query[i].fi].se;
        union_sets(u,v);
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans) cout << i << '\n';
    return 0;
}