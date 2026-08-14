#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[N];
ll M = 2111992;
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
    int n,k;
    cin >> n >> k;
    f[1] = 2;
    for(int i = 2;i <= n;i++) {
        if(i-k-1 > 0) f[i] = (f[i-1] + f[i-k-1]) % M;
        else f[i] = (f[i-1] + 1)%M;
    }
    cout << f[n];
    return 0;
}