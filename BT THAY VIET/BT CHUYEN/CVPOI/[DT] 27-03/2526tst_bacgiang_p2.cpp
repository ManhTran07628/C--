#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,t,a[MM],b[MM],dif[MM];

namespace subtask1
{
    void solve()
    {
        for(int i = 1;i <= t;i++) {
            dif[ a[i] ]++;
            dif[ b[i] + 1 ]--;
        }

        int res = 0;
        for(int i = 1;i <= n;i++) {
            dif[i] += dif[i-1];
            if(dif[i] % 3 == 0) res++;
        }
        cout << res;
    }
}

namespace subtask2
{
    map<int,int> coord;
    vector<pii> st;
    void solve()
    {
        ll res = 0;
        coord[1] = 0;
        coord[n + 1] = 0;
        for(int i = 1;i <= t;i++) {
            coord[ a[i] ]++;
            coord[ b[i] + 1 ]--;
        }
        ll cur = 0;
        for(auto x:coord) {
            st.push_back(x);
            // cout << x.fi << ' ' << x.se << '\n';
        }
        sort(st.begin(),st.end());
        for(int i = 0;i < st.size() - 1;i++) {
            cur += st[i].se;
            if(cur % 3 == 0) {
                res += st[i+1].fi - st[i].fi;
                // cout << st[i+1].fi << ' ' << st[i].fi <?< '\n';
            }
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
    cin >> n >> t;
    for(int i = 1;i <= t;i++) {
        cin >> a[i] >> b[i];
    }
    subtask2::solve();
    return 0;
}