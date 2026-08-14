#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int xs,ys,xt,yt,K,SP = 0,U[MM],V[MM];

namespace subtask1
{
    int res = 0,sz = 0;
    vector<int> Node;
    struct Edge{int u,v,id;} items[MM];
    map<pii,int> adj;

    bool cmp(Edge a,Edge b) {
        return a.id < b.id;
    }

    void solve()
    {
        for(int i = 1;i <= K;i++) {
            int u = U[i], v = V[i];
            items[i] = {u,v,i};
        }
        // items[0] = {xs,ys,0};
        // items[K+1] = {xt,yt,K+1};
        sz = K;
        for(int mask = 0;mask < (1 << sz);mask++) {
            vector<Edge> submask;
            for(int i = 0;i < sz;i++) {
                if(mask >> i & 1) {
                    submask.push_back(items[i+1]);
                }
            }
            sort(submask.begin(),submask.end(),cmp);
            int cur_sz = submask.size();
            do
            {
                ll dist = 0;
                for(int i = 1;i < cur_sz;i++) {
                    int X1 = submask[i - 1].u, Y1 = submask[i - 1].v;
                    int X2 = submask[i].u, Y2 = submask[i].v;
                    int dis = max(abs(X1 - X2),abs(Y1 - Y2));
                    dist += dis; 
                }
                if(cur_sz > 0) {
                    dist += max(abs(xs - submask[0].u),abs(ys - submask[0].v));
                    dist += max(abs(xt - submask[cur_sz - 1].u),abs(yt - submask[cur_sz - 1].v));
                }
                if(dist <= SP) res = max(res,cur_sz);
            } while (next_permutation(submask.begin(),submask.end(),cmp));
        }
        cout << res;
    }
}

namespace subtask23
{
    vector<pii> topo;
    int dp[MM];

    bool cmp(pii a,pii b)
    {
        return a.se < b.se;
    }

    void solve()
    {
        for(int i = 1;i <= K;i++) {
            int u = U[i], v = V[i];
            int distS = max(abs(xs - u),abs(ys - v));
            int distT = max(abs(xt - u),abs(yt - v));
            if(distS + distT != SP) continue;

            topo.push_back({distS,i});
        }
        sort(topo.begin(),topo.end());

        int sz = topo.size();

        for(int i = 0;i < sz;i++) {
            dp[i] = 1;
            for(int j = 0;j < i;j++) {
                int idi = topo[i].se, idj = topo[j].se;
                int X1 = U[idi], Y1 = V[idi];
                int X2 = U[idj], Y2 = V[idj];
                int distIJ = max(abs(X1 - X2),abs(Y1 - Y2));
                int distS = topo[j].fi, distT = topo[i].fi;
                if(distS + distIJ == distT) 
                    dp[i] = max(dp[i],dp[j] + 1);
            }
        }
            
        int res = 0;
        for(int i = 0;i < sz;i++)
            res = max(res,dp[i]);
        cout << res;
    }   
}

namespace subtask4
{
    vector<pii> point;

    void solve()
    {
        int new_xs = xs + ys, new_ys = xs - ys;
        int new_xt = xt + yt, new_yt = xt - yt;
        xs = new_xs, ys = new_ys;
        xt = new_xt, yt = new_yt;

        for(int i = 1;i <= K;i++) {
            int x = U[i] + V[i];
            int y = U[i] - V[i];
            U[i] = x;
            V[i] = y;

            if(min(xs,xt) <= x && x <= max(xs,xt) && min(ys,yt) <= y && y <= max(ys,yt)) {
                int u = (xs <= xt) ? x : -x;
                int v = (ys <= yt) ? y : -y;
                point.push_back({u,v});
            }
        }
        sort(point.begin(),point.end());
        vector<int> v;
        for(int i = 0;i < point.size();i++) {
            int pos = upper_bound(v.begin(),v.end(),point[i].se) - v.begin();
            if(pos == v.size()) v.push_back(point[i].se);
            else v[pos] = point[i].se;
        }
        cout << v.size();
    }
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
    cin >> xs >> ys >> xt >> yt >> K;
    SP = max(abs(xs - xt),abs(ys - yt));
    for(int i = 1;i <= K;i++) {
        int u,v; cin >> u >> v;
        U[i] = u, V[i] = v;
    }
    subtask4::solve();
    return 0;
}
