#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,k,x[MM];

namespace subtask1
{
    void solve()
    {
        for(int i = 1;i < n;i++) {
            if(x[i] > x[i + 1]) {
                swap(x[i],x[i + 1]);
                break;
            }
        }
        for(int i = 1;i <= n;i++) cout << x[i] << ' ';
    }
}

namespace subtask2
{
    vector<int> vec;
    void solve()
    {
        for(int i = 1;i <= n;i++) vec.push_back(x[i]);
        for(int i = 0;i < n && k > 0;i++) {
            int nxt_pos = i;
            for(int j = i + 1;j <= min(n - 1,i + k);j++) {
                if(vec[nxt_pos] > vec[j]) {
                    nxt_pos = j;
                }
            }

            if(nxt_pos != i) {
                k -= (nxt_pos - i);
                int val = vec[nxt_pos];
                vec.erase(vec.begin() + nxt_pos);
                vec.insert(vec.begin() + i, val);
            }

            // cout << k << ": ";
        }
        for(auto e:vec) cout << e << ' '; ;//cout << '\n';

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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> x[i];
    subtask2::solve();
    return 0;
}