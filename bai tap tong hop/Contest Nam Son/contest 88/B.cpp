#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
const int MOD = 68718952446;
int t,n;
int a[MAXN],mp[MAXN];
unordered_map<int,int> expo;

void min_prime()
{
    for(int i = 2;i*i < MAXN;i++)
        if(mp[i] == 0)
            for(int j = i;j < MAXN;j+=i)
                if(mp[j] == 0) 
                    mp[j] = i;
    for(int i = 2;i < MAXN;i++)
        if(mp[i] == 0) 
            mp[i] = i;
}

int binpow(int a,int b)
{
    int ans = 1;
    while(b > 0) {
        if(b % 2) ans = ans * a % MOD;
        b /= 2;
        a = a * a % MOD;
    }
    return ans;
}

void factorize(int k)
{
    while(k > 1) {
        expo[mp[k]]++;
        k /= mp[k];
    }
}

int calc(int k)
{
    int ans = 1;
    for(auto [p,cnt]:expo) {
        int cntk = 0;
        while(k % p == 0) {
            cntk++;
            k /= p;
        }
        ans = (ans%MOD*binpow(p,cnt-cntk)%MOD)%MOD;
    }
    return ans;
}

void solve()
{
    min_prime();
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            factorize(a[i]);
        }
        for(int i = 1;i <= n;i++) {
            cout << calc(a[i]) << ' ';
        }
        cout << '\n';
        expo.clear();
    }
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}