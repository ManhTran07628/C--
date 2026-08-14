#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 4e3 + 7;
int H,W,L,P;
pii a[(int) 1e5 + 7];
int d[MM][MM];

int getsum(int X1,int Y1,int X2,int Y2)
{
    return d[X2][Y2] - d[X2][Y1 - 1] - d[X1 - 1][Y2] + d[X1 - 1][Y1 - 1];
}

namespace subtask1
{
    void solve()
    {
        for(int i = 1;i <= H;i++)
            for(int j = 1;j <= W;j++)
                d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1];

        ll cnt = 0;
        for(int len = L;len <= min(W,H);len++) {
            for(int x = 1;x + len - 1 <= H;x++)
                for(int y = 1;y + len - 1 <= W;y++) {
                    int u = x + len - 1, v = y + len - 1;
                    bool ok = (!getsum(x,y,x,v) && !getsum(x,v,u,v) &&
                    !getsum(x,y,u,y) && !getsum(u,y,u,v));
                    cnt += ok;
                }
        }
    cout << cnt;
    }
}

namespace subtask2
{
    void solve()
    {
        ll res = 0;
        vector<int> badsize;
        for(int r = 1;r <= H;r++)
            for(int c = 1;c <= W;c++) {
                int max_s = min(H - r + 1,W - c + 1);
                
                badsize.clear();

                for(int i = 1;i <= P;i++) {
                    int br = a[i].fi, bc = a[i].se;
                    if(br == r && bc >= c) max_s = min(max_s,bc - c);
                    if(bc == c && br >= r) max_s = min(max_s,br - r);
                    if(br > r && bc > c) 
                        badsize.push_back(max({br - r + 1,bc - c + 1}));
                }
                
                if(max_s < L) continue;
                res += max_s - L + 1;

                sort(badsize.begin(),badsize.end());
                badsize.erase(unique(badsize.begin(),badsize.end()),badsize.end());
                for(auto sz:badsize) if(L <= sz && sz <= max_s) res--;

            }
        cout << res;
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
    cin >> H >> W >> L >> P;
    for(int i = 1;i <= P;i++) {
        cin >> a[i].fi >> a[i].se;
        d[ a[i].fi ][ a[i].se ] = 1;
    }
    if(H <= 500 && W <= 500) subtask1::solve();
    else subtask2::solve();
    
    return 0;
}