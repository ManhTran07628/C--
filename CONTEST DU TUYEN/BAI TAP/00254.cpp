#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e6 + 7;
struct Node{ll L,R,id;};

ll bfs(ll node)
{
    ll res = 1;
    queue<Node> q;
    q.push({1,node,1});
    while(!q.empty()) {
        Node N = q.front(); q.pop();
        ll L = N.L, R = N.R, id = N.id;
        if(L == R) {
            res = max(res,id);
            continue;
        }
        ll mid = (L + R) / 2; 
        q.push({L,mid,id * 2});
        q.push({mid + 1,R,id * 2 + 1});
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 1;i <= 100;i++) cout << i << ' ' << bfs(i) << '\n';
    // int q; cin >> q;
    // while(q--) {
    //     ll n;
    //     cin >> n;
    //     cout << bfs(n) << ' ';
    // }
    return 0;
}