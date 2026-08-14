#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e5 + 7;
int n,m,h[MM],s[MM],f[MM];



namespace subtask1
{
    int del[MM] = {},ok = 0;
    vector<int> vec,res;

    bool check()
    {
        for(int i = 1;i <= m;i++) {
            if(del[i]) continue;
            for(int j = s[i];j <= f[i];j++) {
                if(vec[j - 1] < h[i]) return 0;
            }
        }
        return 1;
    }

    void solve()
    {
        for(int i = 1;i <= m;i++) {
            for(int i = 1;i <= n;i++) vec.push_back(i);
            del[i] = 1;
            
            do
            {
                if(check()) {
                    res = vec;
                    ok = 1;
                    break;
                }
            } while(next_permutation(vec.begin(),vec.end()));
            
            del[i] = 0;
            
            vec.clear();
        }

        if(ok) {
            cout << "POSSIBLE" << '\n';
            for(auto x:res) cout << x << ' ';
        }
        else cout << "IMPOSSIBLE" << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "CITY"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) cin >> h[i] >> s[i] >> f[i];
    subtask1::solve();
    return 0;
}