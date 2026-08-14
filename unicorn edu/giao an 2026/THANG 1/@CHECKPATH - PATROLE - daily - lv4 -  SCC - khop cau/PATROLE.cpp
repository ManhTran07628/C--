#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b / __gcd(a,b)
#define I first
#define II second
#define pb push_back
#define ii pair<int,int>
const int INF = 2 * 1e9;
const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
int n,m,num[N],low[N],cnt,t,d[N],deg[N];
vector<int> g[N],g1[N];
bool vs[N];
stack<int> q;
ii e[N];
  void dfs(int u)
   {
       num[u]=low[u]=++cnt;
       q.push(u);
         for (int v : g[u])
          if (num[v]) low[u]=min(low[u],num[v]); else
          {
              dfs(v);
              low[u]=min(low[u],low[v]);
          }
        if (num[u]==low[u])
        {
            int v=0;t++;
            while (v!=u)
            {
                v=q.top();q.pop();
                d[v]=t;
                num[v]=low[v]=INF;
            }
        }
   }
   void dfs1(int u)
    {
        vs[u]=true;
        for (int v : g1[u])
        {
            dfs1(v);
            return ;
        }
    }
    int main()
        {
        #define TASKNAME "patrole"
            ios_base::sync_with_stdio(0);
            cin.tie(0);
        if (fopen(TASKNAME".inp","r" )) {
            freopen(TASKNAME".inp","r",stdin);
            freopen(TASKNAME".out","w",stdout); }
            cin>>n>>m;
            for (int i=1;i<=m;i++)
            {
                int u,v;
                cin>>u>>v;
                u++,v++;
                g[u].pb(v);
                e[i]={u,v};
            }
            for (int i=1;i<=n;i++)
                if (!num[i]) dfs(i);
            for (int i=1;i<=m;i++)
            {
                int u=e[i].I,v=e[i].II;
                if (d[u]!=d[v]) g1[d[u]].pb(d[v]),deg[d[v]]++;
            }
            if (t==1)
            {
                for (int i=1;i<=n;i++) cout<<i-1<<'\n';
            } else
            {
                for (int i=1;i<=t;i++)
                    if (g1[i].size()==1 && !deg[i])
                {
                    dfs1(i);
                    for (int j=1;j<=t;j++)
                        if (!vs[j])
                    {
                        cout<<-1;
                        return 0;
                    }
                    for (int j=1;j<=n;j++)
                        if (d[j]==i) cout<<j-1<<'\n';
                    return 0;
                }
                cout<<-1;
            }
            return 0;
        }