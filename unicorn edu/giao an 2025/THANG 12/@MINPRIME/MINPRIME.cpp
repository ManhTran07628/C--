#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MAXN = 2e6+7;
int n,a[MAXN],mp[MAXN],cnt[MAXN];
void min_prime()
{
    for(int i = 2;i*i < MAXN;i++)
        if(mp[i] == 0)
            for(int j = i;j < MAXN;j+=i)
                if(mp[j] == 0) mp[j] = i;
    for(int i = 2;i < MAXN;i++) 
        if(mp[i] == 0) mp[i] = i;
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    min_prime();
    for(int i = 1;i <= n;i++) {
        int k = a[i];
        while(k > 1) {
            int p = mp[k];
            while(k % p == 0) {
                cnt[p]++;
                k /= p;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(cnt[i]) cout << i << ' ' << cnt[i] << '\n';
    }
    return 0;
}

