#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n,q,divs[MAXN],max_prime[MAXN];
bool prime[MAXN];
void sieve()
{
    for(int i = 2;i < MAXN;i++) prime[i] = 1;
    for(int i = 2;i*i < MAXN-5;i++)   
        if(prime[i]) 
            for(int j = i*i;j < MAXN-5;j+=i) 
                prime[j] = 0;

    for(int i = 2;i*i < MAXN-5;i++) 
        if(prime[i])
            for(int j = i;j < MAXN-5;j+=i)
                divs[j] = i;
}

void solve()
{
    sieve();
    // for(int i = 1;i <= 10;i++) cout << i << ' ' << divs[i] << '\n';
    while(q--) {
        int k;
        cin >> k;
        int l = 1,r = n,ans = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            if(divs[mid] <= k) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    solve();
    return 0;
}