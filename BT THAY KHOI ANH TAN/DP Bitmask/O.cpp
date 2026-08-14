#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 1e5+7;
int t,n,m,state_V = 0;
string s;
int med[MM],eff[MM],d[MM],cost[MM];
void readinput()
{
    cin >> n >> m >> s;
    state_V = 0;
    for(int i = 0;i < n;i++) {
        state_V += ((s[i] - '0') << (n - 1 - i));
    }
    
    for(int j = 1;j <= m;j++) {
        cin >> cost[j];
        cin >> s;
        med[j] = eff[j] = 0;
        for(int i = 0;i < n;i++) {
            med[j] += ((s[i] - '0') << (n - 1 - i));
        }
        cin >> s;
        
        for(int i = 0;i < n;i++) {
            eff[j] += ((s[i] - '0') << (n - 1 - i));
        }
    }
}

struct Node{int mask,dist_m;};
struct cmp{
    bool operator() (Node &a, Node &b) {
        return a.dist_m > b.dist_m;
    }
};

void dijkstra()
{
    fill(d,d+MM,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({state_V,0});
    d[state_V] = 0;
    while(!q.empty()) {
        auto N = q.top(); q.pop();
        int mask = N.mask;
        for(int i = 1;i <= m;i++) {
            int cur_mask = mask;

            cur_mask &= (~med[i]);

            cur_mask |= eff[i];
            if(d[cur_mask] > d[mask] + cost[i]) {
                d[cur_mask] = d[mask] + cost[i];
                q.push({cur_mask,d[cur_mask]});
            }
        }
    }   
}

void solve()
{
    readinput();
    dijkstra();
    cout << (d[0] != oo ? d[0] : -1) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}