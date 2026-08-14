#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,m,parent[MM],sz[MM],query[MM],size_comp = 1;
vector<int> adj[MM];

int find_set(int a)
{
    if(a == parent[a]) return a;
    return parent[a] = find_set(parent[a]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        size_comp = max(size_comp,sz[a]);
    }
}

void make_set(int a)
{
    parent[a] = a;
    sz[a] = 1;
    for(int b:adj[a]) {
        if(parent[b] != 0) {
            union_sets(a,b);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) {
        cin >> query[i];
    }
    vector<int> ans;
    for(int i = n;i >= 1;i--) {
        make_set(query[i]);
        if(size_comp != n-i+1) ans.push_back(0);
        else ans.push_back(1);
    }
    cout << '\n';
    reverse(ans.begin(),ans.end());
    for(auto i:ans) cout << (i ? "YES" : "NO") << '\n';
    return 0;
}