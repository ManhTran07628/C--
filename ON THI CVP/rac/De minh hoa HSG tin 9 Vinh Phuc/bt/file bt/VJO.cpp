#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[N],s[N];

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
    ll t;
    cin >> t;
    while(t--)
    {
         ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        ll ddchan = 0,ddle = 0,maxchan = -1,maxle = -1;
        for(int i = 1;i <= n;i++) {
            if(i % 2 == 0) {
                maxchan = max(maxchan,a[i]);
                ddchan++;
            }
            else {
                maxle = max(maxle,a[i]);
                ddle++;
            }
        }
        cout << max(maxchan+ddchan,maxle+ddle) << '\n';
    }
    return 0;
}