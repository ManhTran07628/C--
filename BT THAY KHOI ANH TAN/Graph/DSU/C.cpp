#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int parent[MM],sz[MM],query[MM],d[MM];
pair<int,int> edge[MM];
int n,m,q,comp;
vector<int> ans;
void make_set()
{
    for(int i = 1;i <= n;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

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
        comp--;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    make_set();
    comp = n;
    for(int i = 1;i <= m;i++) {
        cin >> edge[i].fi >> edge[i].se;

    }
    for(int i = 1;i <= q;i++) {
        cin >> query[i];
        d[query[i]] = 1;
    }

    for(int i = 1;i <= m;i++) {
        if(!d[i]) {
            union_sets(edge[i].fi,edge[i].se);
        }
    }

    for(int i = q;i >= 1;i--) {
        ans.push_back(comp);
        union_sets(edge[query[i]].fi,edge[query[i]].se);
    }



    reverse(ans.begin(),ans.end());
    for(auto i:ans) cout << i << '\n';
    return 0;
}