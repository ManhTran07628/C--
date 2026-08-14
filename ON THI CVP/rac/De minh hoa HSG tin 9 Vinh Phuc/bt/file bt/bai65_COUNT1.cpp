#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll chan[N],le[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "COUNT1"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i =1;i <= n;i++) {
        ll a;
        cin >> a;
        chan[i] = chan[i-1] + chan[i];
        le[i] = le[i-1] + le[i];
        if(a % 2 == 0) chan[i]++;
        else le[i]++;
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) { // le so chan - chan so le
        for(int j = i;j <= n;j++) {
            ll sochan = chan[j] - chan[i-1];
            ll sole = le[j] - le[i-1];
            if(sochan % 2 != 0 && sole % 2 == 0) dem++;
        }
    }
    cout << dem;
    return 0;
}