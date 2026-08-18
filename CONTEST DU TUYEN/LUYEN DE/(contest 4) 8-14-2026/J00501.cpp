#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e6 + 7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
const int MOD_ans = 1e9 + 7;
const int base = 256;
string S;
int k,sz;
ll HashS[MM][2],Pow[MM][2],dp[MM];

ll getHash(int L,int R,int t)
{
    return (HashS[R][t] - HashS[L - 1][t] * Pow[R - L + 1][t] % MOD[t] + MOD[t]) % MOD[t];
}

ll getkey(int L,int R)
{
    ll h1 = getHash(L,R,0), h2 = getHash(L,R,1);
    ll key = (h1 << 32) | h2;
    return key;
}

unordered_map<ll,ll> mp;
vector<int> Length;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> S >> k;
    sz = S.size();
    S = ' ' + S;

    Pow[0][0] = Pow[0][1] = 1;
    for(int i = 1;i <= sz;i++) {
        Pow[i][0] = (Pow[i - 1][0] * base) % MOD[0];
        Pow[i][1] = (Pow[i - 1][1] * base) % MOD[1];

        HashS[i][0] = (HashS[i - 1][0] * base + S[i] - '0' + 1) % MOD[0];
        HashS[i][1] = (HashS[i - 1][1] * base + S[i] - '0' + 1) % MOD[1];
    }

    for(int q = 1;q <= k;q++) {
        string t; cin >> t;
        int t_sz = t.size();
        t = ' ' + t;
        ll h1 = 0, h2 = 0;
        for(int i = 1;i <= t_sz;i++) {
            h1 = (h1 * base + t[i] - '0' + 1) % MOD[0];
            h2 = (h2 * base + t[i] - '0' + 1) % MOD[1];
        }  
        ll key = (h1 << 32) | h2;
        mp[key]++;
        Length.push_back(t_sz);
    }
    sort(Length.begin(),Length.end());
    Length.erase(unique(Length.begin(),Length.end()),Length.end());

    dp[0] = 1;



    for(int j = 1;j <= sz;j++) {

        for(auto len:Length) {
            if(j - len + 1 < 1) break;
            int i = j - len + 1;
            ll key = getkey(i,j);
            if(mp.find(key) != mp.end()) {
                int cnt = mp[key];
                dp[j] = (dp[j] + dp[i - 1] * cnt) % MOD_ans;
            }
        }
    }
    cout << dp[sz];
    return 0;
}