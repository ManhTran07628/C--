#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int MOD = 2019;
int n;
string s;

namespace subtask1
{
    void solve()
    {   
        ll res = 0;
        for(int L = 1;L <= n;L++) 
            for(int R = L + 1;R <= n;R++) {

                ll sum = 0;
                for(int j = L;j <= R;j++) {
                    sum = (sum * 10 + s[j] - '0') % MOD;
                }

                res += (sum == 0);
            }

            
        cout << res;
    }
}

namespace subtask2
{
    map<ll,ll> mp;
    void solve()
    {
        ll sum = 0,x = 1;
        ll res = 0;
        reverse(s.begin(),s.end());
        mp[0] = 1;
        for(int i = 0;i < n;i++) {
            // cout << sum << ' ';
            sum = ((s[i] - '0') * x + sum) % MOD;
            res += mp[sum];
            mp[sum]++;
            x *= 10; x %= MOD;
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    subtask2::solve();
    return 0;   
}