#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e6;
const int MM = 1000+7;
int a[MM][MM],n,T,k;
vector<int> adj[MM];
pair<int,int> query[MM];
void init()
{
    cin >> n >> T >> k;
    for(int i = 1;i <= T;i++) {
        cin >> query[i].fi >> query[i].se; 
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            if(a[i][j]) adj[i].push_back(j);
        }
    }
}


namespace solk1
{
    vector<int> adjq[MM],path;
    int color[MM],par[MM],maxsize = 0;
    int vis[MM],h[MM];

    void buildpath(int L,int R,vector<int> &path)
    {
        path.clear();
        path.push_back(L);
        for(int v = L+1;v <= R;v++) {
            int pos = 0;
            while(pos < path.size() && a[path[pos]][v]) pos++;
            path.insert(path.begin()+pos,v);
        }
    }

    void solvek1(int q)
    {
        int L = query[q].fi, R = query[q].se;

        // reset du lieu
        buildpath(L,R,path);
        if(path.size() != 0) {
            cout << path.size() << ' ';
            for(auto i:path) cout << i << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';

    }
    void solve()
    {
        for(int q = 1;q <= T;q++) {
            solvek1(q);
        }
    }
}

namespace solk2
{
    vector<int> adjq[MM],path;
    int color[MM],par[MM],st = -1,en = -1,minsize = oo;

    void cyclefinding(int u)
    {
        color[u] = 1;
        for(auto v:adjq[u]) {
            if(color[v] == 0) {
                par[v] = u;
                cyclefinding(v);
            }
            else if(color[v] == 1) {
                if(par[u] != v) {
                    st = v;
                    en = u;
                    vector<int> curpath;
                    int cur = en;
                    while(cur != st) {
                        curpath.push_back(cur);
                        cur = par[cur];
                    }
                    curpath.push_back(st);
                    reverse(curpath.begin(),curpath.end());
                    if(curpath.size() < minsize) {
                        path.clear();
                        minsize = curpath.size();
                        for(auto i:curpath) path.push_back(i);
                    }
                }
            }
        }
        color[u] = 2;
    }

    void solvek2(int q)
    {
        int L = query[q].fi, R = query[q].se;

        // reset du lieu
        for(int i = 1;i <= n;i++) adjq[i].clear();
        path.clear();
        memset(color,0,sizeof(color));
        memset(par,0,sizeof(par));
        minsize = oo;
        st = -1,en = -1;


        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(a[i][j] && L <= i && i <= R && L <= j && j <= R) 
                    adjq[i].push_back(j);
            }
        }
        for(int i = 1;i <= n;i++) {
            if(!color[i] && L <= i && i <= R) {
                cyclefinding(i);
            }
        }

        if(st == -1) cout << -1 << '\n';
        else {
            cout << path.size() << ' ';
            for(auto v:path) cout << v << ' ';
            cout << '\n';
        }
    }

    void solve()
    {
        for(int q = 1;q <= T;q++) {
            solvek2(q);
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "FOOTBALL"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    if(k == 1) solk1::solve();
    else solk2::solve();
    return 0;
}