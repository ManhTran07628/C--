#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 2e5+7;
int n,p;
ll mp[MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    string s; cin >> s;
    s = ' ' + s;
    mp[0] = 1;
    ll MOD = p, nums = 1, sum = 0, res = 0;
    for(int i = n;i >= 1;i--) {
        sum = ( (s[i] - '0') * nums + sum ) % MOD;
        res += mp[sum];
        mp[sum]++;
        nums *= 10; nums %= MOD;
    }
    cout << res;
    return 0;
}