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
const int N = 500 + 1;
const int MOD = 1e9 + 7;
char a[N];
int n,x[N],y[N],ans[N];
struct dta
  {
      int i1,i2,t1,t2;
      bool t;
  };
vector<dta> g;
    int main()
        {
        #define TASKNAME "infpaint"
            ios_base::sync_with_stdio(0);
            cin.tie(0);
        if (fopen(TASKNAME".inp","r" )) {
            freopen(TASKNAME".inp","r",stdin);
            freopen(TASKNAME".out","w",stdout); }
            cin>>n;
            for (int i=1;i<=n;i++) cin>>a[i]>>x[i]>>y[i];
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                  if (a[i]!=a[j])
            {
                if (a[i]=='E' && a[j]=='N' && x[i]<x[j] && y[i]>=y[j] && x[j]-x[i]>y[i]-y[j])
                  g.pb({i,j,x[j]-x[i],y[i]-y[j],1}); else
                if (a[i]=='N' && a[j]=='E' && x[i]>=x[j] && y[i]<=y[j] && x[i]-x[j]<y[j]-y[i])
                  g.pb({i,j,y[j]-y[i],x[i]-x[j],1});
            }
            memset(ans,0,sizeof(ans));
            while (1)
            {
                int mn=-1;
                for (int i=0;i<g.size();i++)
                    if (g[i].t)
                {
                     if (mn==-1) mn=i; else
                        if (g[i].t1<g[mn].t1) mn=i;
                }
                if (mn==-1) break;
                dta v=g[mn];
                if (ans[v.i1]==0 && (ans[v.i2]==0 || v.t2<ans[v.i2]))
                    ans[v.i1]=v.t1;
                g[mn].t=false;
            }
            for (int i=1;i<=n;i++)
              if (ans[i]==0) cout<<"Infinity"<<'\n'; else cout<<ans[i]<<'\n';
            return 0;
        }