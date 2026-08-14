#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 7e6+7;
const int MOD = 1e9 + 7;
const int base = 256;
string s;
ll n,hashA[MM],Pow[MM],ps[MM];

ll getHash(int l,int r)
{
    return (hashA[r] - hashA[l - 1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "BRACKET"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> s;
    s = ' ' + s + s;

    Pow[0] = 1;
    for(int i = 1;i <= n * 2;i++) {
        Pow[i] = (Pow[i-1] * base) % MOD;
        ps[i] = ps[i-1] + (s[i] == '(' ? 1 : -1);
    }

    for(int i = 1;i <= n * 2;i++) 
        hashA[i] = (hashA[i-1] * base + (s[i] == '(' ? 1 : 2) + 1) % MOD;
    
    set<ll> s;
    deque<ll> dq;
    for(int i = 1;i <= n * 2;i++) {
        while(!dq.empty() && dq.front() <= i - n) dq.pop_front();
        while(!dq.empty() && ps[ dq.back() ] >= ps[i]) dq.pop_back();
        dq.push_back(i);
        if(i - n >= 0) {
            int l = i - n + 1;
            if(ps[ dq.front() ] - ps[l - 1] >= 0 && ps[i] - ps[l - 1] == 0 ){
                s.insert(getHash(l,i));
            }
        }
    }
    cout << s.size();
    return 0;
}