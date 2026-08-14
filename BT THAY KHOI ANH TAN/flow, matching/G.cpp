    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fi first
    #define se second
    #define oo (ll) 1e9
    const int MM = 5e3 + 7;
    int n,m,s,t;
    int d[MM],cur_id[MM];
    struct Edge{int u,v,flow,cap,rev_id;};
    vector<int> adj[MM];
    vector<Edge> edges;

    void add_edges(int u,int v,int cap)
    {
        int fw = edges.size();
        int rev = fw + 1;
        adj[u].push_back(fw);
        adj[v].push_back(rev);

        edges.push_back({u,v,0,cap,rev});
        edges.push_back({v,u,0,0,fw});
    }

    void bfs()
    {
        fill(d+1,d+n+4,oo);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto id:adj[u]) {
                auto E = edges[id];
                int v = E.v;
                if(d[v] != oo || E.flow == E.cap) continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    int dfs(int u,int cur_delta)
    {
        if(cur_delta == 0) return 0;
        if(u == t) return cur_delta;
        for(; cur_id[u] < adj[u].size(); cur_id[u]++) {
            int id = adj[u][ cur_id[u] ];
            auto E = edges[id];
            int v = E.v, rev_id = E.rev_id;
            if(d[v] != d[u] + 1 || E.flow == E.cap) continue;

            int delta = dfs(v, min(E.cap - E.flow, cur_delta));

            if(delta == 0) continue;
            edges[id].flow += delta;
            edges[rev_id].flow -= delta;
            return delta;
        }
        return 0;
    }

    signed main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        #define taskname ""
        if(fopen(taskname ".inp","r")) {
            freopen(taskname ".inp","r",stdin);
            freopen(taskname ".out","w",stdout);
        }
        cin >> n >> m >> s >> t; s++; t++;
        for(int i = 1;i <= m;i++) {
            int u,v,w; cin >> u >> v >> w;
            u++; v++;
            add_edges(u,v,w);
        }

        int max_flow = 0;
        while(1) {
            bfs();
            if(d[t] == oo) break;
            for(int i = 1;i <= n;i++) cur_id[i] = 0;
            while(int delta = dfs(s,oo)) 
                max_flow += delta;
        }

        int max_flow_edges = 0;
        vector<Edge> vec;
        for(int i = 0;i < edges.size();i += 2) {
            if(edges[i].flow > 0) {
                max_flow_edges++;
                vec.push_back(edges[i]);
            }
        }

        
        cout << n << ' ' << max_flow << ' ' << max_flow_edges << '\n';

        sort(vec.begin(),vec.end(), [] (Edge a, Edge b){
            if(a.u != b.u) return a.u < b.u;
            return a.v < b.v;
        });

        for(auto E:vec) {
            cout << E.u - 1 << ' ' << E.v - 1 << ' ' << E.flow << '\n';
        }

        // for(int i = 0;i < edges.size();i += 2) {
        //     if(edges[i].flow > 0) {
        //         cout << edges[i].u - 1 << ' ' << edges[i].v - 1 << ' ' << edges[i].flow << '\n';
        //     }
        // }
        return 0;
    }