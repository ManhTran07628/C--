#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int MOD = 10007;
int n,m,nums[MM],color[MM];
vector<int> adj[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> nums[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> color[i];
        adj[ color[i] ].push_back(i);
    }
    ll res = 0;
    for(int i = 1;i <= n;i++) {

        int pos = lower_bound(adj[ color[i] ].begin(),adj[ color[i] ].end(),i) - adj[ color[i] ].begin();

        for(int x = pos;x < adj[ color[i] ].size();x++) {
            int j = adj[ color[i] ][x];

            if( (j - i - 1) >= 1 && (j - i + 1) % 2 == 1 ) {
                cout << i << ' ' << j << ' ' << '\n';
                res += (i * j) * (nums[i] * nums[j]);
                res %= MOD;
            }

        }

    }
    cout << res;

    return 0;
}