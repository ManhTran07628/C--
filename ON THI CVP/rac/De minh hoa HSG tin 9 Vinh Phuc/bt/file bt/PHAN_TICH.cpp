#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PHANTICH"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll tm = i;
        for(int j = 2;j <= sqrt(i);j++) {
            while(tm % j == 0) {
                f[j]++;
                tm /= j;
            }
        }
        if(tm > 1) f[tm]++;
    }
    for(int i = 1;i <= n;i++) {
        if(f[i] != 0) cout << i << " " << f[i] << '\n';
    }
    return 0;
}