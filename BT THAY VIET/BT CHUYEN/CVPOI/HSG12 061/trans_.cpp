#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int k,n,c,usage[MM],vis[MM];
struct Event{int s,e,m,id;} events[MM];
vector<Event> adj[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    
    cin >> k >> n >> c;
    for(int i = 1;i <= k;i++) {
        cin >> events[i].s >> events[i].e >> events[i].m;
        events[i].id = i;
        adj[ events[i].s ].push_back(events[i]);
    }

    for(int i = 1;i <= k;i++) {
        sort(adj[i].begin(),adj[i].end(),[] (Event a,Event b){return a.s < b.s;});
    }

    multiset<int> incar;
    int res = 0, capacity = 0;
    for(int st = 1;st <= n;st++) {

        vector<int> vec;

        for(auto id:incar) {
            int e = events[id].e;
            int cur_cap = usage[id];
            if(e == st) {
                vec.push_back(id);
                res += cur_cap;
                capacity -= cur_cap;
                usage[id] = 0;
                vis[id] = 1;
            }
        }

        for(auto id:vec) incar.erase(id);

        for(auto id:adj[st]) {
            int en = id.e, max_cap = id.m;
            int j = id.id;
            if(st > en || vis[j]) continue;
            int sz = min(c - capacity,max_cap);
            if(sz > 0) {
                usage[j] = sz;
                capacity += sz;
                incar.insert(j);
            }   
        }

        for(auto id:adj[st]) {
            int en = id.e, max_cap = id.m;
            int j = id.id;
            if(st < en || vis[j]) continue;
            int sz = min(c - capacity,max_cap);
            if(sz > 0) {
                usage[j] = sz;
                capacity += sz;
                incar.insert(j);
            }    
        }
    }

    for(int st = 1;st <= n;st++) {

        vector<int> vec;

        for(auto id:incar) {
            int e = events[id].e;
            int cur_cap = usage[id];
            if(e == st) {
                vec.push_back(id);
                res += cur_cap;
                capacity -= cur_cap;
                usage[id] = 0;
                vis[id] = 1;
            }
        }

        for(auto id:vec) incar.erase(id);

        for(auto id:adj[st]) {
            int en = id.e, max_cap = id.m;
            int j = id.id;
            if(st < en || vis[j]) continue;
            int sz = min(c - capacity,max_cap);
            if(sz > 0) {
                usage[j] = sz;
                capacity += sz;
                incar.insert(j);
            }   
        }
    }

    cout << res;
    return 0;
}