#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m;
ll dist1[MM],cnt1[MM],dist2[MM],cnt2[MM];
vector<pii> adj[MM];
struct Node{ll u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;};
};

void dijkstra(int st,ll dist[],ll cnt[])
{
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    dist[st] = 0;
    cnt[st] = 1;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                q.push({v,dist[v]});
            }
            else if(dist[v] == dist[u] + w) cnt[v] += cnt[u];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // nhan xet : 
    // goi cnt1[i] la so duong di ngan nhat tu 1 -> i
    // cnt2[i] la so duong di ngan nhat tu n -> i
    // đỉnh i có thể được chọn khi d(1,i) + d(i,n) > d(1,n)
    // hoặc d(1,i) + d(i,n) >= d(1,n) và cnt1[i] * cnt2[i] < cnt1[n]
    // tức số cách đi đường đi ngắn nhất từ 1 -> i -> n khác 1 -> n
    // điều này là do khi đường đi này là SP nhưng có đường đi khác cũng có SP nên
    // khi ta xóa đỉnh này và cạnh liên thuộc thì cũng không bị thay đổi SP
    // do đó ta sẽ xét 2 th
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,d; cin >> u >> v >> d;
        adj[u].push_back({v,d});
        adj[v].push_back({u,d});
    }
    dijkstra(1,dist1,cnt1);
    dijkstra(n,dist2,cnt2);
    vector<int> v;
    for(int i = 2;i < n;i++) {
        if(dist1[i] + dist2[i] > dist1[n] || 
            (dist1[i] + dist2[i] == dist1[n] && cnt1[i] * cnt2[i] != cnt1[n]) ) {
            // cout << i << '\n';
            v.push_back(i);
        }
    }
    cout << v.size() << '\n';
    for(auto x:v) cout << x << '\n';
    // cout << cnt[5];
    return 0;
}