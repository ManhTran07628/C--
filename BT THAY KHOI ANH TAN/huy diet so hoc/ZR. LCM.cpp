#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int p[MAXN];
map<int,int> lt;
void min_prime()
{
    for(int i = 2;i*i < MAXN-1;i++) 
        if(p[i] == 0) 
            for(int j = i;j < MAXN-1;j+=i)
                if(p[j] == 0) p[j] = i;
    for(int i = 2;i < MAXN-1;i++) if(p[i] == 0) p[i] = i;
}
ll MOD = 1e9+7;

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0) {
        if(b%2==1) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    min_prime();
    int n;
    cin >> n;
    for(int i = 2;i <= n;i++) {
        int cnt = 0,pre = p[i];
        int k = i;
        while(k > 1) {
            if(pre != p[k]) {
                cnt = 0;
            }
            cnt++;
            lt[p[k]] = max(lt[p[k]],cnt);
            k /= p[k];
        }
    }
    ll ans = 1;
    for(auto i:lt) {
        ll t = binpow(i.fi,i.se);
        ans = (ans%MOD*t%MOD)%MOD;
    }
    cout << ans;
    return 0;
}