#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],f[N],b[N];
ll tmp = 14062008;
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
    for(int i = 1;i <= k;i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    f[1] = 1;
    if(b[2] == 0) 
        f[2] = 2;
    for(int i = 2;i <= n;i++) {
        if(b[i] == 0) {
            f[i] = (f[i-1]+f[i-2]) % tmp;
        }
        else {
            f[i] = 0;
        }
    }
    cout << f[n];
    return 0;
}
