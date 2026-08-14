#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5+7;
pair<int,int> a[MM],query[MM];
int maxl[MM],parent[MM],sz[MM],ok[MM];
vector<pair<int,int>> ans;
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
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
        parent[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i <= q;i++) {
        cin >> query[i].fi;
        query[i].se = i; // fi - gia tri  se - vi tri ban dau
    }
    sort(a+1,a+n+1);
    sort(query+1,query+q+1);
    int i = 1,j = 1;
    int cur_max = 0;
    while(j <= q) {
        while(a[i].fi <= query[j].fi && i <= n) {
            int posA = a[i].se;
            ok[posA] = 1; 
            if(ok[posA-1] && posA-1 >= 1) union_sets(posA,posA-1);
            // ok[posA-1] : neu truoc do co a[posA-1] <= query[j].fi thi tra ve 1 
            if(ok[posA+1] && posA+1 <= n) union_sets(posA,posA+1);
            cur_max = max(cur_max,sz[find_set(posA)]);
            i++;          
        }
        ans.push_back({query[j].se,cur_max});
        j++;
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans) cout << i.se << '\n';
    return 0;
}