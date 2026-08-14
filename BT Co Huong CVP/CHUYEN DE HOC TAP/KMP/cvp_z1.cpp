#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
const int base = 256;
ll Hash[MM][2],Pow[MM][2];
int n,ans[MM];
string s;

ll getHash(int l,int r,int type)
{
    return (Hash[r][type] - Hash[l - 1][type] * 
        Pow[r - l + 1][type] % MOD[type] + MOD[type]) % MOD[type]; 
}

ll getkey(int l,int r)
{
    ll h1 = getHash(l,r,0), h2 = getHash(l,r,1);
    ll key = (h1 << 32) | h2;
    return key;
}

bool check(int len)
{
    int pref_pos = len,  suf_pos = n - len + 1;
    if(getkey(1,pref_pos) != getkey(suf_pos,n)) return 0;

    int cnt = 0;
    for(int i = 1;i + len - 1 <= n;i++) {
        if(getkey(1,len) == getkey(i,i + len - 1)) cnt++;
    }
    return cnt >= 3;
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
    cin >> s;
    n = s.size();
    s = ' ' + s;
    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i <= n;i++) {
        Pow[i][0] = (Pow[i-1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i-1][1] * base) % MOD[1];
    }

    for(int i = 1;i <= n;i++) {
        Hash[i][0] = (Hash[i-1][0] * base + s[i] - '0' + 1) % MOD[0];
        Hash[i][1] = (Hash[i-1][1] * base + s[i] - '0' + 1) % MOD[1];
    }

    vector<int> cur_list;

    for(int i = 1;i <= n;i++) {
        ans[i] = 1;
        if(s[i] == s[1]) cur_list.push_back(i);
    }


    for(int i = 1;i <= n && cur_list.size() > 1;i++) {
        vector<int> new_list;

        for(auto id:cur_list) {
            if(getkey(id,id + i - 1) == getkey(1,i)) {
                new_list.push_back(id);
            }
        }

        ans[i] = new_list.size();
        cur_list = new_list;
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    return 0;
}