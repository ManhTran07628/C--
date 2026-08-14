#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MOD = 1e9 + 7;
ll m,n;

const int MS12 = 2e3;
namespace subtask12
{
    vector<int> valid_[MS12];
    ll dp[MS12][200],f[MS12];
    int kk = 0;

    void gen_state(vector<int> vec,int state_num)
    {
        vector<int> state;
        for(int i = 1;i <= n;i++) state.push_back(i);
        int cnt = 0;
        do 
        {
            ++cnt;
            bool ok = 1;
            for(int i = 0;i < n;i++) 
                if(vec[i] == state[i]) ok = 0;

            if(ok) {
                valid_[state_num].push_back(cnt);
                // if(state_num == 1) {
                    // cout << ++kk << '\n';
                    // for(int i = 0;i < n;i++) cout << vec[i] << ' '; cout << '\n';
                    // for(int i = 0;i < n;i++) cout << state[i] << ' '; 
                    // cout << '\n' << '\n';
                // }
            }

        } while(next_permutation(state.begin(),state.end()));
    }

    void process()
    {
        vector<int> vec;
        for(int i = 1;i <= n;i++) vec.push_back(i);

        int cnt = 0;
        do 
        {   
            // for(auto e:vec) cout << e << ' '; cout << '\n';
            ++cnt;
            gen_state(vec,cnt);
        } while(next_permutation(vec.begin(),vec.end()));
    }

    void solve()
    {
        process();
        f[0] = 1;
        for(int i = 1;i <= n;i++) f[i] = f[i-1] * i;

        for(int i = 1;i <= f[n];i++) dp[1][i] = 1;

        for(int i = 2;i <= m;i++) {

            for(int j = 1;j <= f[n];j++) 
                for(auto k:valid_[j]) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }

        }

        ll res = 0;
        for(int i = 1;i <= f[n];i++) {
            res += dp[m][i];
            res %= MOD;
        }
        cout << res;

        // for(int i = 1;i <= f[n];i++) cout << valid_[i].size() << ' ';
        // cout << valid_[1].size() << ' ' << valid_[2].size();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "ARMY"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> m >> n;
    subtask12::solve();
    return 0;
}