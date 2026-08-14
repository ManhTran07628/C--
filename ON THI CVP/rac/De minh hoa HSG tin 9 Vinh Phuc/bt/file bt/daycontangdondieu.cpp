#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+4;
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        f[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[i] > a[j]) {
                f[i] = max(f[i],f[j]+1);
                max1 = max(max1,f[i]);
            }
        }
    }
    cout << max1;
    return 0;
}