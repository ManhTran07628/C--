#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int MOD = 1e9 + 7;
int n;
ll S,c[MM],Fmod[MM];
vector<int> vec;
ll res = 0, bad_ways = 0;

ll binpow(ll a,ll b)
{
    if(b == 0) return 1;
    ll x = binpow(a,b / 2);
    if(b % 2 == 1) return x * x % MOD * a % MOD;
    return x * x % MOD;
}

ll C(ll k,ll n)
{
    ll C = 1;
    for(ll i = 1;i <= k;i++) {
        C = C * ((n - i + 1) % MOD) % MOD * Fmod[i] % MOD;
    }
    return C;
}

void check(int sz,ll _S)
{   
    if(_S < 0) return;
    if(sz == 0) return;

    ll com = C(n - 1,_S + n - 1);

    if(sz % 2 == 0) bad_ways = (bad_ways - com % MOD + MOD) % MOD;
    else bad_ways = (bad_ways + com % MOD) % MOD;
}

void Try(int id,int sz,ll _S)
{
    if(_S < 0) return;
    if(id > n) {
        check(sz,_S);
        return;
    }

    Try(id + 1,sz,_S);

    vec.push_back(id);
    Try(id + 1,sz + 1,_S - (c[id] + 1));
    vec.pop_back();
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
    cin >> n >> S;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= n;i++) Fmod[i] = binpow(i,MOD - 2);

    res = C(n - 1,S + n - 1);
    Try(1,0,S);
    cout << (res - bad_ways % MOD + MOD) % MOD;
    return 0;
}