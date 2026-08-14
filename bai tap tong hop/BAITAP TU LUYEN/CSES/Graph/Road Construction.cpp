#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5+7;
int parent[MM],sz[MM],n,m;
int max_comp,size_comp;
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
    int p = find_set(parent[a]);
    parent[a] = p;
    return p;
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
        size_comp--;
        max_comp = max(max_comp,sz[a]);
    }
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    make_set();
    max_comp = 1,size_comp = n;
    for(int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        union_sets(a,b);
        cout << size_comp << ' ' << max_comp << '\n';
    }
    return 0;
}