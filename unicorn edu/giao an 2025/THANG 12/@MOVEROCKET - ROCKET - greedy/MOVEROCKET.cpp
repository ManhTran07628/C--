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
int n;
ii r[N],c[N];
vector<pair<int,char> >ans;
  void solve(ii a[],char x,char y)
   {
      sort(a+1,a+n+1);
      vector<ii> p,q;
      for (int i=1;i<=n;i++)
        if (a[i].I-i<0) p.pb({i-a[i].I,a[i].II}); else
            if (a[i].I-i>0) q.pb({a[i].I-i,a[i].II});
      for (int i=p.size()-1;i>=0;i--)
      {
          auto u=p[i];
          for (int j=1;j<=u.I;j++) ans.pb({u.II,y});
      }
      for (auto u : q)
      {
          for (int i=1;i<=u.I;i++) ans.pb({u.II,x});
      }
   }
    int main()
        {
        #define TASKNAME "rocket"
            ios_base::sync_with_stdio(0);
            cin.tie(0);
        if (fopen(TASKNAME".inp","r" )) {
            freopen(TASKNAME".inp","r",stdin);
            freopen(TASKNAME".out","w",stdout); }
            cin>>n;
            for (int i=1;i<=n;i++)
            {
                int u,v;
                cin>>u>>v;
                r[i]={u,i};
                c[i]={v,i};
            }
            solve(r,'U','D');
            solve(c,'L','R');
            cout<<ans.size()<<'\n';
            return 0;
        }