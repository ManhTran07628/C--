#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int p[MM],parent[MM];

int find_set(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = find_set(parent[u]);
}

void union_sets(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    parent[a] = b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        parent[i] = i;
    }
    for(int i = 1;i <= n;i++) {
        cin >> p[i];
        int k = find_set(p[i]);
        cout << k << ' ';
        int k1 = k%n+1;
        union_sets(k,k1);
    }
    return 0;
}