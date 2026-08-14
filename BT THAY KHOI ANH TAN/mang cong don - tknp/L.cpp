#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],prime[MAXN],cost[MAXN];
vector<int> p;
void sieve()
{
    fill(prime+1,prime+MAXN+1,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i < MAXN;i++)   
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
    for(int i = 2;i < MAXN;i++) if(prime[i]) p.push_back(i);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        int pos = lower_bound(p.begin(),p.end(),a[i])-p.begin();
        cost[i] = min(abs(a[i]-p[pos]),abs(a[i]-p[max(0LL,pos-1)]));
        cost[i] += cost[i-1];
    }
    int i = 1,j = 1,ans = 1e10;;
    while(i <= n && j <= n) {
        if(j-i+1 < k) j++; 
        else {
            ans = min(ans,cost[j]-cost[i-1]);
            i++;
        }
    }
    cout << ans;
    return 0;
}