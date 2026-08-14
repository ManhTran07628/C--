#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,t,a[MM],v[MM],parent[MM],sz[MM];
int d[MM],sum[MM],ans = 0;
vector<int> f;
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
        parent[b] = a;
        sum[a] += sum[b];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        parent[i] = i;
        sum[i] = a[i];
        sz[i] = 1;
    }
    d[0] = d[n+1] = 1;
    for(int i = 1;i <= t;i++) {
        cin >> v[i];
        d[v[i]] = 1;
    }
    for(int i = 1;i <= n;i++) {
        if(!d[i] && !d[i+1]) {
            union_sets(i,i+1);
        }
        if(!d[i]) ans = max(ans,sum[find_set(i)]);
    }
    for(int i = t;i >= 1;i--) {
        sum[v[i]] = a[v[i]];
        f.push_back(ans);
        if(v[i] > 1 && !d[v[i]-1]) union_sets(v[i],v[i]-1);
        if(v[i] < n && !d[v[i]+1]) union_sets(v[i],v[i]+1);
        ans = max(ans,sum[v[i]]);
        d[v[i]] = 0;
    }
    reverse(f.begin(),f.end());
    for(auto i:f) cout << i << '\n';
    return 0;
}