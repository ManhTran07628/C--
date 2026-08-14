#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int prime[MAXN];
void sieve()
{
    for(int i = 2;i < MAXN;i++) prime[i] = 1;
    for(int i = 2;i*i < MAXN;i++)
        if(prime[i])
            for(int j = i*i;j < MAXN;j+=i)
                prime[j] = 0;
}

int cntdivs(int a,int k)
{
    int cnt = 0;
    while(a > 0) {
        cnt += a / k;
        a /= k;
    }
    return cnt;
}

void solve()
{
    sieve();
    int n,m,cnt = 0;
    cin >> n >> m;
    for(int i = 2;i <= n;i++) {
        if(prime[i]) 
            if(cntdivs(n,i)-cntdivs(m,i)-cntdivs(n-m,i) > 0) cnt++;
        
    }
    cout << cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}