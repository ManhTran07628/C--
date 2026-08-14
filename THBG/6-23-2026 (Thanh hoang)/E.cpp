#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int LOG = 18;
int n,q;

namespace subtask123
{
    struct DSU
    {
        int par[MM] = {}, Max[MM] = {}, Min[MM] = {};
        void build()
        {
            for(int i = 1;i <= n;i++) {
                par[i] = Max[i] = Min[i] = i;
            }
        }

        int find_sets(int a)
        {
            if(a == par[a]) return a;
            return par[a] = find_sets(par[a]);
        }

        void Unite(int a,int b)
        {
            a = find_sets(a);
            b = find_sets(b);
            if(a == b) return;
            par[b] = a;
            Max[a] = max(Max[a],Max[b]);
            Min[a] = min(Min[a],Min[b]);
        }
    } g;

    void solve()
    {
        g.build();
        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int x; cin >> x;
                cout << g.Min[g.find_sets(x)] << ' ' << g.Max[g.find_sets(x)] << '\n';
            }
            else {
                int l,r,len; cin >> l >> r >> len;
                for(int i = 1;i <= len;i++) {
                    g.Unite(l + i - 1,r + i - 1);
                }
            }
        }
    }
}

namespace sol
{
    struct DSU
    {
        int par[MM][LOG + 1] = {}, Max[MM] = {}, Min[MM] = {};

        void build()
        {
            for(int i = 1;i <= n;i++) {
                Max[i] = i;
                Min[i] = i;
            }

            for(int j = 0;j <= LOG;j++)
                for(int i = 1;i <= n;i++)
                    par[i][j] = i;
        }   

        int find_sets(int a,int k)
        {
            if(a == par[a][k]) return a;
            return par[a][k] = find_sets(par[a][k],k);
        }

        void Unite(int a,int b,int k)
        {
            int root_a = find_sets(a,k);
            int root_b = find_sets(b,k);
            if(root_a == root_b) return;
            par[root_b][k] = root_a;
            if(k == 0) {
                Max[root_a] = max(Max[root_a],Max[root_b]);
                Min[root_a] = min(Min[root_a],Min[root_b]);
            }
            else {
                int half = (1 << (k - 1));
                Unite(a,b,k - 1);
                Unite(a + (1 << k) - half,b + (1 << k) - half,k - 1);
            }
        }
    } g;

    void solve()
    {
        g.build();
        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int x; cin >> x;
                cout << g.Min[g.find_sets(x,0)] << ' ' << g.Max[g.find_sets(x,0)] << '\n';
            }
            else {
                int l,r,len; cin >> l >> r >> len;
                int k = __lg(len);
                g.Unite(l,r,k);
                g.Unite(l + len - (1 << k),r + len - (1 << k),k);
            }
        }
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
    cin >> n >> q;
    sol::solve();
    return 0;
}