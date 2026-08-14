#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
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
    ll ans = 0;
    for(int i = 1;i < n;i++) {
        ll cnt = 1;
        for(int j = i;j < n;j++) {
            if(a[j] < a[j+1]) cnt++;
            else break;
        }
        f[i] = cnt;
        ans = max(ans,cnt);
    }
    f[n] = 1;
    cout << ans << '\n';
    for(int i = 1;i <= n;i++) {
        if(f[i] == ans) {
            for(int j = i;j < n;j++) {
                if(a[j] < a[j+1]) cout << a[j] << ' ';
                else {
                    cout << a[j];
                    return 0;
                }
            }
        }
    }
    return 0;
}