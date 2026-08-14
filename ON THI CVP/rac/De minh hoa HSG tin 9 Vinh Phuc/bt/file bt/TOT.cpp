#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+1;
ll a[N],b[N];
map<ll,ll> c;

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
    ll n,dem = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        if(c[a1] == 0) {
            a[i] = a1;
            b[i] = -a1;
            c[a1] = 1;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            for(int k = j+1;k <= n;k++) {
                ll ans = b[i] + a[j] + a[k];
                if(ans == 0) {
                    dem++;
                }
            }
        }
    }
    cout << dem;
    return 0;
}