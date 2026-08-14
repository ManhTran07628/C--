#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e6 + 7;
int n,t,a[MM];


namespace subtask2
{
    map<int,int> mp;
    int suf[MM],pf[MM];
    void solve()
    {
        for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + (a[i] == t);
        for(int i = 1;i <= n;i++) pf[i] = pf[i - 1] + (a[i] == t);
        int res = suf[1] - 1;


        for(int i = 1;i <= n;i++) {
            int x = t - a[i], cnt = (a[i] == t ? 0 : 1);
            for(int j = i - 1;j >= 1;j--) {
                if(a[j] + x == t) cnt++;
                res = max(res,pf[j - 1] + suf[i + 1] + cnt);

            }
        }
        cout << res;
    }
}

namespace subtask3
{
    int st[MM * 4][51];

    void update(int id,int l,int r,int pos,int val,int type)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id][type] = max(st[id][type],val);
            return;
        }
        int mid = (l + r) / 2;
        update(id*2,l,mid,pos,val,type);
        update(id*2+1,mid+1,r,pos,val,type);
        st[id][type] = max(st[id * 2][type],st[id * 2 + 1][type]);
    }

    int get(int id,int l,int r,int u,int v,int type)
    {
        if(l > v || r < u) return -oo;
        if(u <= l && r <= v) return st[id][type];
        int mid = (l + r) / 2;
        return max(get(id*2,l,mid,u,v,type), get(id*2+1,mid+1,r,u,v,type));
    }

    
    int suf[MM],pf[MM],ps[MM][51];
    int pfmax[51];
    void solve()
    {
        for(int i = n;i >= 1;i--) suf[i] = suf[i + 1] + (a[i] == t);
        for(int i = 1;i <= n;i++) pf[i] = pf[i - 1] + (a[i] == t);

        int res = suf[1] - 1;

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= 50;j++) {
                ps[i][j] = ps[i - 1][j];
            }
            ps[i][ a[i] ]++;
        }
        // suf[R + 1] + get(L,R) + pf[L - 1]
        // suf[R + 1] + ps[R] +  (-ps[L - 1] + pf[L - 1])

        for(int R = 1;R <= n;R++) {

            for(int i = 1;i <= 50;i++) {
                update(1,1,n,R,-ps[R - 1][i] + pf[R - 1],i);
            }

            int val = get(1,1,n,1,R,a[R]);
            res = max(res,suf[R + 1] + ps[R][ a[R] ] + val);

            // update(1,1,n,R,,a[R]);
        }

        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "A"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".ans","w",stdout);
    }
    cin >> n >> t;
    for(int i = 1;i <= n;i++) cin >> a[i];
    subtask2::solve();
    return 0;
}