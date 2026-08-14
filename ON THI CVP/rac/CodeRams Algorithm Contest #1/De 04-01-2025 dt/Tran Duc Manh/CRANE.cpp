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
    #define taskname "CRANE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll sum = 0,cnt = 0;
        for(int j = i;j <= n;j++) {
            sum+=a[j];
            if(sum <= k) {
                cnt++;
            }
            else break;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}