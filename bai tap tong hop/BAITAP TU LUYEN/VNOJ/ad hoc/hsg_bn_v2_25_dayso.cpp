#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e4 + 7;
int n,q,a[MM];

namespace subtask12
{
    int ps[1001][1001];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++)
                ps[i][j] += ps[i-1][j];
            ps[i][ a[i] ]++; 
        } 

        while(q--) {
            int x,y,u,v; cin >> x >> y >> u >> v;
            ll res = 0;
            for(int i = 1;i <= n;i++) {
                res += (1ll * ps[y][i] - ps[x - 1][i]) * (1ll * ps[v][i] - ps[u - 1][i]);
            }
            cout << res << '\n';
        }
    }
}

namespace subtask3
{
    int ps[MM][51];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= 50;j++)
                ps[i][j] += ps[i-1][j];
            ps[i][ a[i] ]++;
        }

        while(q--) {
            int x,y,u,v; cin >> x >> y >> u >> v;
            ll res = 0;
            for(int i = 1;i <= 50;i++) {
                res += (1ll * ps[y][i] - ps[x - 1][i]) * (1ll * ps[v][i] - ps[u - 1][i]);
            }
            cout << res << '\n';
        }
    }
}

namespace subtask4
{
    const int blockSize = 230;

    map<pii,int> mp;
    vector<pii> qr;

    struct QR{int x,y,u,v;};
    vector<QR> old_qr;

    bool cmp(pii a,pii b)
    {
        int pa = a.fi / blockSize, pb = b.fi / blockSize;
        if(pa != pb) return pa < pb;
        return a.se > b.se;
    }
    int cntL[MM],cntR[MM];
    ll res = 0;

    void add_L(int x)
    {
        cntL[x]++;
        res += cntR[x];
    }

    void add_R(int x)
    {
        cntR[x]++;
        res += cntL[x];
    }

    void del_L(int x)
    {
        cntL[x]--;
        res -= cntR[x];
    }

    void del_R(int x)
    {
        cntR[x]--;
        res -= cntL[x];
    }


    void solve()
    {
        for(int i = 1;i <= q;i++) {
            int x,y,u,v; cin >> x >> y >> u >> v;
            old_qr.push_back({x,y,u,v});
            qr.push_back({min(y,v),max(y,v)});
            qr.push_back({min(y,u - 1),max(y,u - 1)});
            qr.push_back({min(x - 1,v),max(x - 1,v)});
            qr.push_back({min(x - 1,u - 1),max(x - 1,u - 1)});
            // mp[{min(y,v),max(y,v)}] = 1;
            // mp[{min(y,u - 1),max(y,u - 1)}] = 1;
            // mp[{min(x - 1,v),max(x - 1,v)}] = 1;
            // mp[{min(x - 1,u - 1),max(x - 1,u - 1)}] = 1;
        }

        sort(qr.begin(),qr.end(),cmp);
        qr.erase(unique(qr.begin(),qr.end()),qr.end());

        int l = 0, r = 0;
        for(int i = 0;i < qr.size();i++) {
            while(l < qr[i].fi) add_L(a[++l]);
            while(r < qr[i].se) add_R(a[++r]);
            while(l > qr[i].fi) del_L(a[l--]);
            while(r > qr[i].se) del_R(a[r--]);

            mp[{l,r}] = res;
        }

        for(auto [x,y,u,v] : old_qr) {
            ll a = mp[{min(y,v),max(y,v)}], b = mp[{min(y,u - 1),max(y,u - 1)}];
            ll c = mp[{min(x - 1,v),max(x - 1,v)}], d = mp[{min(x - 1,u - 1),max(x - 1,u - 1)}];
            ll cur_res = a - b - c + d;
            cout << cur_res << '\n';
        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "dayso"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // subtask4::solve();
    if(n <= 1000 && q <= 1000) subtask12::solve();
    else if(*max_element(a+1,a+n+1) <= 50) subtask3::solve();
    else subtask4::solve();
    return 0;
}