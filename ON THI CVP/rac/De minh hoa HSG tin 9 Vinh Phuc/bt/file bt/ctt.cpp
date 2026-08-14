#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],f[N],b[N];

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
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    for(int i = 1;i <= n;i++) 
        cin >> b[i];  
    ll max1 = 0;  
    for(int i = 1;i <= n;i++) {
        f[i] = 0;
        for(int j = 1;j < i;j++) {
            if(abs(a[i]-a[j] >= k)) {
                f[i] = max(f[i],f[j]+b[j]);
            }
        }
        max1 = max(max1,f[i]+b[i]);
    }
    cout << max1;
    return 0;
}