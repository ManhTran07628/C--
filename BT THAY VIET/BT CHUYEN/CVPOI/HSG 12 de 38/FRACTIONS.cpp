#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int mp[MM],pdiv[MM];
vector<int> Div[MM];

void sieve()
{
    for(ll i = 2;i * i < MM;i++)
        if(mp[i] == 0) 
            for(ll j = i * i;j < MM;j += i) {
                if(mp[j] == 0)
                    mp[j] = i;
            }

    
    for(int i = 2;i < MM;i++)
        if(mp[i] == 0) mp[i] = i;
}

void process()
{
    for(int i = 2;i < MM;i++) {
        if(mp[i] == i) continue;
        int x = i;
        while(x > 1) {
            int p = mp[x];
            Div[i].push_back(p);
            while(x % p == 0) x /= p;
        }
    }
}

ll cntvalid(ll nums)
{
    int sz = Div[nums].size();
    ll cur_res = 0;
    for(int mask = 1;mask < (1 << sz);mask++) {

        ll cur_nums = 1;
        for(int j = 0;j < sz;j++)
            if(mask >> j & 1) 
                cur_nums *= Div[nums][j];

        int mask_sz = __builtin_popcount(mask);
        // cout << cur_nums << '\n';
        if(mask_sz % 2 == 1) cur_res += nums / cur_nums;
        else cur_res -= nums / cur_nums;
    }
    return nums - cur_res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    ll n; cin >> n;
    ll cnt = 1;

    process();
    for(int i = 2;i <= n;i++) {

        if(mp[i] == i) cnt += i - 1;
        else cnt += cntvalid(i);

    }
    cout << cnt;

    return 0;
}