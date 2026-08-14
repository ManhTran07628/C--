#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
const int MOD = 1e9 + 7;
int n,T,a[MM];

namespace subtask1
{
    vector<int> vec,f;
    ll pos[MM], res = 0, cnt = 0;
    map<vector<string>,int> mp;

    // 0 - L  1 - R   2 - None

    void check() 
    {
        bool ok = 1;
        vector<string> d;
        for(int i = 1;i <= n;i++) pos[i] = 0;
        for(int i = 0;i < T;i++) {
            if(f[i] == 2) {
                ok = 0;
                continue;
            }
            if(f[i] == 1) {
                pos[ vec[i] ]++;
            }
            if(f[i] == 0) {
                pos[ vec[i] ]--;
            }
        }
        for(int i = 1;i <= n;i++) {
            if(pos[i] != a[i]) return;
        }

        for(int i = 0;i < T;i++) {
            if(f[i] == 0) d.push_back("T" + to_string(vec[i]));
            if(f[i] == 1) d.push_back("P" + to_string(vec[i]));
            if(f[i] == 2) d.push_back("N");
        }

        if(!ok) {
            if(mp.find(d) == mp.end()) {
                mp[d] = 1;
                res++;
            }
            cnt++;
        }
        else res++;
        res %= MOD;
    }

    void Try2(int id)
    {
        if(id == T) {
            check();
            return;
        }

        for(int i = 1;i <= n;i++) {
            vec.push_back(i);
            Try2(id + 1);
            vec.pop_back();
        }
    }

    void Try(int id)
    {
        if(id == T) {
            Try2(0);
            return;
        }

        f.push_back(0);
        Try(id+1);
        f.pop_back();

        f.push_back(1);
        Try(id+1);
        f.pop_back();

        f.push_back(2);
        Try(id+1);
        f.pop_back();
    }

    void solve()
    {
        Try(0);
        cout << res;// << ' ' << cnt;
    }
}

namespace subtask3
{
    ll d[MM + MM][MM];
    ll dfs(int u,int cur_time)
    {
        if(cur_time > T) return 1;
        if(d[u][cur_time] != -1) return d[u][cur_time];
        ll memo = (dfs(u - 1,cur_time + 1) % MOD + 
        dfs(u + 1,cur_time + 1) % MOD + dfs(u,cur_time + 1) % MOD) % MOD;
        d[u][cur_time] = memo;
        return memo;
    }

    void solve()
    {
        memset(d,-1,sizeof(d));
        dfs(1000,0);
        cout << d[ a[1] + 1000 ][T];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "sol"
    // if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".ans","w",stdout);
    // }
    cin >> n >> T;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // if(n <= 5 && T <= 5) subtask1::solve();
    // else subtask3::solve();
    // subtask3::solve();
    subtask1::solve();
    return 0;
}