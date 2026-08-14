#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
const ll base = 131;
const ll MOD = 1e9+7;

int n,k;
string s;

bool check(ll t)
{
    ll hashS[50001];
    ll POW[50001];
    map<ll,int> lt;
    POW[0] = 1;
    for(int i = 1;i <= n;i++) {
        POW[i] = (base*POW[i-1])%MOD;
    }
    for(int i = 1;i <= n;i++) {
        hashS[i] = (hashS[i-1]*base+s[i]-'a'+1)%MOD;
    }

    for(int i = 1;i <= n-t+1;i++) {
        int j = i+t-1;
        ll hashP = (hashS[j]-hashS[i-1]*POW[j-i+1]%MOD+MOD)%MOD;
        lt[hashP]++;
    }
    for(auto i:lt) if(i.se >= k) return 1;
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> s;
    s = " "+s;
    int L = 1,R = n,ans = -1;
    while(L <= R) {
        int mid = (L+R)/2;
        if(check(mid)) {
            ans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << ans;
    return 0;
}