#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],f[N];

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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    } 
    f[0] = 0;
    ll max1 = -1e9;
    fill(f+1,f+n+1,-1e9);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i - j >= 0) {
                f[i] = max(f[i],f[i-j]+a[i]);
            }
            else {
                f[i] = max(f[i],f[0]);
            }
        }
        max1 = max(max1,f[i]);
    }
    cout << max1;
    return 0;
}
