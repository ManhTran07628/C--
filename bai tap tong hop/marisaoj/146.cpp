#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int p[N],f[101][2001];

void sieve()
{
    fill(p+1,p+N+1,1);
    p[1] = p[0] = 0;
    for(int i = 2;i*i < N;i++)
        if(p[i])
            for(int j = i*2;j < N;j+=i)
                p[j] = 0;
}
int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    int n,k;
    cin >> n >> k;
    for(int i = 0;i <= k;i++) f[1][i] = 1;
    for(int i = 2;i <= n;i++) {
        for(int j = 0;j <= k;j++) {
            for(int h = 0;h <= k;h++) {
                if(p[j+h]) f[i][j] = (f[i-1][h] + f[i][j]) % M;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i <= k;i++) ans = (ans+f[n][i]) % M;
    cout << ans;
    return 0;
}