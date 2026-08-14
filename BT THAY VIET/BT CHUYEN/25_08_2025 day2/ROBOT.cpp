#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,a[MM],m;

void init()
{
    cin >> n;
    for(int i = 1;i <= n*2+1;i++) {
        cin >> a[i];
    }
    m = n*2+1;
}

namespace subtask1
{
    const int MS1 = 100;
    int dp[MS1][MS1],ans = 1e6;

    struct dl
    {
        int idL,idR,c;
    } color[MS1];


    void Try(int l,int r,int steps)
    {
        if(l > m || r < 1) return;
        if(l == 1 && r == m) {
            ans = min(ans,steps);
            return;
        }
        if(l-1 >= 1 && r+1 <= m) {
            if(color[l-1].c == color[r+1].c) 
                Try(color[l-1].idL,color[r+1].idR,steps+1);
        }
        if(l-1 >= 1) Try(color[l-1].idL,r,steps+1);
        if(r+1 <= m) Try(l,color[r+1].idR,steps+1);
    }

    void solve()
    {
        for(int L = 1,R = 1;L <= m;) {
            int c = a[L];
            while(R <= m && a[L] == a[R]) {
                R++;
            }
            for(int i = L;i < R;i++) {
                color[i].idL = L;
                color[i].idR = R-1;
                color[i].c = c;
            }
            L = R;
        }
        Try(color[n+1].idL,color[n+1].idR,0);
        cout << ans;
    }
}

namespace subtask2
{
    const int MS1 = 2007;
    ll dp[MS1][MS1];
    vector<int> c;
    void solve() {
        c.push_back(0);
        for(int i = 1;i <= m;i++) {
            if(i == m || a[i] != a[i+1]) 
                c.push_back(a[i]);
        }
        m = c.size()-1;

        for(int len = 2;len <= m;len++) {
            for(int l = 1;l <= m-len+1;l++) {
                int r = l+len-1;
                if(c[l] == c[r]) dp[l][r] = dp[l+1][r-1] + 1;
                else dp[l][r] = min(dp[l+1][r],dp[l][r-1]) + 1;
            }
        }
        cout << dp[1][m];
    }
}

namespace subtask3
{
    int dp[MM],Ln,Rn;
    vector<int> pos[MM],s,L,R;
    vector<pair<int,int>> P;

    void process()
    {
        s.push_back(0);
        L.push_back(0);
        R.push_back(0);
        for(int i = 1;i <= m;i++) {
            if(a[i] != a[i+1] || i == m) 
                s.push_back(a[i]);
        }   
        m = s.size()-1;
        int mid = (m+1)/2;
        for(int i = mid-1;i >= 1;i--) {
            L.push_back(s[i]);
        }
        for(int i = mid+1;i <= m;i++) {
            R.push_back(s[i]);
        }
        Ln = L.size()-1;
        Rn = R.size()-1;

        for(int i = 1;i <= Rn;i++) pos[R[i]].push_back(i);
        for(int i = 1;i <= Ln;i++) {
            for(auto v: pos[L[i]]) P.push_back({i,v});
        }

        sort(P.begin(),P.end(), [] (pair<int,int> &a,pair<int,int> &b){
            if(a.fi != b.fi) return a.fi < b.fi;
            return a.se > b.se;
        });

    }


    struct SegTree
    {
        vector<int> st;
        SegTree(int n) : st(n*4+1) {};

        void update(int id,int l,int r,int pos,int val)
        {
            if(l > pos || r < pos) return;
            if(l == r) {
                st[id] = max(st[id],val);
                return;
            }
            int mid = (l+r)/2;
            update(id*2,l,mid,pos,val);
            update(id*2+1,mid+1,r,pos,val);
            st[id] = max(st[id*2],st[id*2+1]);
        }

        int get(int id,int l,int r,int u,int v)
        {
            if(l > v || r < u) return 0;
            if(u <= l && r <= v) return st[id];
            int mid = (l+r)/2;
            return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
        }
    };

    void solve()
    {
        process();
        SegTree g(m+7);
        int ans = 0;
        for(int i = 0;i < P.size();i++) {
            int b = P[i].se;
            dp[i] = g.get(1,1,m,1,b-1)+1;
            g.update(1,1,m,b,dp[i]);
            ans = max(ans,dp[i]);
        }
        cout << Ln + Rn - ans;
    }

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "ROBOT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    // if(n <= 10) subtask1::solve();
    // else if(n <= 2000) subtask2::solve();
    subtask3::solve();
    return 0;
}