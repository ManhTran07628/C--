#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll n;
map<int,int> mp;

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
    for(int i = 1;i <= n;i++) {
        int a,b; cin >> a >> b;
        mp[a]++;
        mp[b + 1]--;
    }
    int sum = 0, res = 0;
    int lastpos = -1;
    for(auto id:mp) {
        sum += id.se;
        // cout << id.fi << ' ' << sum << '\n';
        res = max(res,sum);
    }
    cout << res;
    return 0;
}