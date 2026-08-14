#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,q,a[MM];


namespace subtask1
{
    void solve()
    {
        while(q--) {
            int x; cin >> x;
            for(int i = 1;i <= n;i++) {
                if(a[i] % x == 0) a[i] /= x;
            }
        }
        for(int i = 1;i <= n;i++) cout << a[i] << ' ';
    }
}

namespace subtask2
{
    int cur[MM];
    void solve()
    {
        int sz = *max_element(a+1,a+n+1);
        for(int i = 1;i <= n;i++) {
            cur[ a[i] ] = a[i];
        }
        while(q--) {
            int x; cin >> x;
            for(int i = x;i <= sz;i += x) {
                if(cur[i] && cur[i] % x == 0)
                    cur[i] /= x;
            }
        }
        for(int i = 1;i <= n;i++) cout << cur[ a[i] ] << ' ';
    }
}

namespace sol
{
    int cur[MM];
    vector<int> adj[MM];
    void solve()
    {
        int sz = *max_element(a+1,a+n+1);
        for(int i = 1;i <= n;i++) {
            adj[ a[i] ].push_back(i);
            cur[ a[i] ] = a[i];
        }

        while(q--) {
            int x; cin >> x;
            if(x > sz) continue;
            int First = sz / x * x;
            for(int val = First;val >= x;val -= x) {
                if(adj[val].size() == 0) continue;

                for(auto id:adj[val]) {
                    cur[ a[id] ] /= x;
                    adj[ cur[ a[id] ] ].push_back(id);
                }
                adj[val].clear();
            }
        }

        for(int i = 1;i <= n;i++) cout << cur[ a[i] ] << ' ';
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    sol::solve();
    return 0;
}