#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<ll,ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "countsquares"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            f[a[i]]++;
        }
        if(n < 4) {
            cout << -1 << '\n';
            f.clear();
            continue;
        }
        ll kq = 0,s = 0;
        for(int i = 1;i <= 1000;i++) {
            if(f[i] >= 4) {
                s = i*i;
                kq = f[i] / 4;
            }
        }
        if(kq == 0 && s == 0) {
            cout << -1 << '\n';
            f.clear();
            continue;
        }
        cout << s << " " << kq << '\n';
        f.clear();
    }
    return 0;
}