#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll b[N],c[N];

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
        cin >> b[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    sort(c+1,c+n+1);
    ll ans = 1e9;
    for(int i = 1;i <= n;i++) {
        ll pos = lower_bound(c+1,c+n+1,-b[i]) - c;
        if(pos == n+1) {
            ans = min(ans,abs(c[1]+b[i]));
        }
        else {
            ans = min(ans,abs(c[pos]+b[i]));
        }
    }
    cout << ans;
    return 0;
}