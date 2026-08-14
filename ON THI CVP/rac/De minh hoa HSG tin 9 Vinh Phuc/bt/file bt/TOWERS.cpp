#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
ll f[N];
ll l[N],r[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "tower"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll rmax = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> l[i] >> r[i];
        rmax = max(rmax,l[i]);
    }
    f[l[1]] = r[1];
    ll ans = f[l[1]]; 
    for(int i = 2;i <= n;i++) {
        for(int j = l[i];j <= rmax;j++) {
            f[l[i]] = max(f[l[i]],f[j]+r[i]);
            ans = max(ans,f[l[i]]);
        }
    }
    cout << ans;
    return 0;
}



