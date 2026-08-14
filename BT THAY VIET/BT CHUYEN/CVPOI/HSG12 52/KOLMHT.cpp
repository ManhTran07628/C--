#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e3 + 7;
int n,x[MM],y[MM],U[MM],V[MM];


namespace subtask1
{
    ll res = oo;
    vector<int> c1,c2;

    void readans()
    {
        ll ans = 0;
        for(auto i:c1) {
            for(auto j:c1) {
                ans = max(ans,(ll) abs(x[i] - x[j]) + abs(y[i] - y[j]));
            }
        }

        for(auto i:c2) {
            for(auto j:c2) {
                ans = max(ans,(ll) abs(x[i] - x[j]) + abs(y[i] - y[j]));
            }
        }

        res = min(res,ans);
    }

    void Try(int id)
    {
        if(id > n) {
            readans();
            return;
        }
        
        c1.push_back(id);
        Try(id+1);
        c1.pop_back();

        c2.push_back(id);
        Try(id+1);
        c2.pop_back();
    }

    void solve()
    {
        Try(1);
        cout << res;
    }
}

namespace subtask2
{
    bool check(ll D)
    {
        map<int,ll> color;
        for(int i = 1; i <= n; i++) {
            if(color.find(i) == color.end()) {
                queue<int> q;
                q.push({i});
                color[i] = 1;
                while(!q.empty()) {
                    int u = q.front(); q.pop();
                    int u1 = U[u], v1 = V[u], cur_color = color[u];
                    for(int i = 1;i <= n;i++) {
                        if(i == u) continue;
                        ll u2 = U[i], v2 = V[i];
                        ll cur_D = max(abs(u1 - u2),abs(v1 - v2));
                        if(cur_D > D) {
                            if(color.find(i) == color.end()) {
                                q.push(i);
                                color[i] = (cur_color == 1 ? 2 : 1);
                            }
                            else if(cur_color == color[i]) return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }

    void solve()
    {
        // cout << check(8);
        ll L = 0, R = 1e10, res = 0;
        while(L <= R) {
            ll mid = (L + R) / 2;
            if(check(mid)) {
                res = mid;
                R = mid - 1;
            }
            else L = mid + 1;
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
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> x[i];
    for(int i = 1;i <= n;i++) {
        cin >> y[i];
        U[i] = x[i] + y[i];
        V[i] = x[i] - y[i];
    }
    subtask2::solve();
    return 0;
}