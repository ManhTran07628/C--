#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define BIT(x,i) ((x) & (1 << i))
#define pii pair<int,int>
const int MM = 1e6 + 7;
const int LOG = 20;
int n,a[MM];

int F(int x,int y)
{
    int cnt = 0;
    for(int j = 0;j <= 20;j++) {
        if(BIT(x,j) && BIT(y,j) && BIT(x,j+1) && BIT(y,j+1)) cnt++;
    }
    return cnt;
}
namespace subtask1
{
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            int res = 0;
            for(int j = 1;j <= n;j++) {
                if(i == j) continue;
                res = max(res,F(a[i],a[j]));
            }
            cout << res << ' ';
        }
    }
}

namespace subtask2
{
    vector<int> adj[LOG + 1];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j <= LOG;j++) {
                if(BIT(a[i],j) && BIT(a[i],j+1)) 
                    adj[j].push_back(i);
            }
        }

        for(int i = 1;i <= n;i++) {

            int res = 0;
            for(int j = 0;j <= LOG;j++) {

                if(BIT(a[i],j) && BIT(a[i],j+1)) {
                    for(auto x:adj[j]) {
                        if(x != i)
                            res = max(res,F(a[i],a[x]));
                    }
                }

            }
            cout << res << ' ';

        }
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n <= 2000) subtask1::solve();
    else subtask2::solve();
    return 0;
}