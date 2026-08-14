#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "prize"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        cin >> a[i];
    }
    sort(a+1,a+m+1);
    ll cnt = 1,ans = 0;
    for(int i = m;i >= 1;i--) {
        if(cnt <= n) {
            ans = max(ans,cnt*a[i]);
            cnt++;
        }
    }
    cout << ans;
    return 0;
}