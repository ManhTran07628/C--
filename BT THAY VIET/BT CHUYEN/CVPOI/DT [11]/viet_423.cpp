#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,q,h[MM];
struct QR{int l,r,x,id;} qr[MM];

namespace subtask1
{
    void solve()
    {
        for(int t = 1;t <= q;t++) {
            bool ok = 0;
            int res = 0;
            for(int i = qr[t].l;i <= qr[t].r;i++) {
                if(h[i] <= qr[t].x) ok = 0;
                else {
                    if(ok == 0) {
                        ok = 1;
                        res++;
                    }
                }
            }

            cout << res << '\n';
        }
    }
}

namespace subtask2
{
    int res = 0;

    bool checksub2()
    {
        for(int i = 1;i <= q;i++) {
            if(qr[i].l != 1 || qr[i].r != n) return 0;
        }
        return 1;
    }

    struct DSU
    {
        int par[MM] = {};
        void build()
        {
            for(int i = 1;i < MM;i++) 
                par[i] = i;
        }

        int find_sets(int a)
        {
            if(a == par[a]) return a;
            return par[a] = find_sets(par[a]);
        }

        void Unite(int a,int b,int &res)
        {
            a = find_sets(a);
            b = find_sets(b);
            if(a == b) return;
            res--;
            par[b] = a;
        }
    } g;

    pii a[MM];
    int vis[MM],ans[MM],comp[MM];

    void solve()
    {
        g.build();
        vector<int> vec;
        for(int i = 1;i <= n;i++) vec.push_back(h[i]);
        for(int i = 1;i <= q;i++) vec.push_back(qr[i].x);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());

        for(int i = 1;i <= n;i++) h[i] = lower_bound(vec.begin(),vec.end(),h[i]) - vec.begin();
        for(int i = 1;i <= q;i++) qr[i].x = lower_bound(vec.begin(),vec.end(),qr[i].x) - vec.begin();

        for(int i = 1;i <= n;i++) {
            // cout << h[i] << ' ';
            a[i] = {h[i],i};
        }

        // cout << '\n';
        
        sort(a+1,a+n+1,greater<pii>());
        sort(qr+1,qr+q+1,[] (QR a,QR b){return a.x > b.x;});
        
        // for(int i = 1;i <= n;i++) cout << a[i].fi << ' '; cout << '\n';

        for(int i = 1, j = 1;i <= q;i++) {
            int l = qr[i].l, r = qr[i].r, x = qr[i].x, id = qr[i].id;
            while(j <= n && a[j].fi > x) {
                if(a[j].se - 1 >= 1 && vis[ a[j].se - 1 ]) g.Unite(a[j].se,a[j].se - 1,res);
                if(a[j].se + 1 <= n && vis[ a[j].se + 1 ]) g.Unite(a[j].se,a[j].se + 1,res);
                vis[ a[j].se ] = 1;
                j++;
            }
            int cur = res + j - 1;
            ans[id] = cur;
        }


        // for(int i = 1;i <= n;i++) cout << i << ' ' << g.find_sets(i) << '\n';
        for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

    }
}

namespace subtask4
{
    int vis[MM] = {},ans[MM] = {};
    pii a[MM];

    int bit_C[MM] = {}, bit_P[MM] = {};

    void update(int x,int val,int bit[])
    {
        for(;x <= n;x += x & (-x)) bit[x] += val;
    }

    int get(int x,int bit[])
    {
        int res = 0;
        for(;x > 0;x -= x & (-x)) res += bit[x];
        return res;
    }

    int getrange(int l,int r,int bit[])
    {
        return get(r,bit) - get(l - 1,bit);
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            a[i] = {h[i],i};
        }
        sort(a+1,a+n+1,[] (pii a,pii b){return a.fi > b.fi;});
        sort(qr+1,qr+q+1,[] (QR a,QR b){return a.x > b.x;});


        for(int t = 1,i = 1;t <= q;t++) {
            int l = qr[t].l, r = qr[t].r, x = qr[t].x, id = qr[t].id;
            while(i <= n && a[i].fi > x) {
                update(a[i].se,1,bit_C);
                if(vis[ a[i].se + 1 ]) update(a[i].se,1,bit_P);
                if(vis[ a[i].se - 1 ]) update(a[i].se - 1,1,bit_P);
                vis[ a[i].se ] = 1;
                i++;
            }
            ans[id] = getrange(l,r,bit_C) - getrange(l,r - 1,bit_P);
        }

        for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

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
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].x;
        qr[i].id = i;
    }
    // subtask4::solve();
    if(n <= 2000 && q <= 2000) subtask1::solve();
    else if(subtask2::checksub2()) subtask2::solve();
    else subtask4::solve();
    return 0;
}