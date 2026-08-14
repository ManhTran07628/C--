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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,L,R;
    cin >> n >> L >> R;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = -1e18;
    for(int i = 1;i <= n;i++) {
        ll sum = 0;
        for(int j = i;j <= n;j++) {
            sum += a[j];
            if(j-i+1 >= L && j-i+1 <= R) {
                ans = max(ans,sum);
            }
            else if(j-i+1 > R) break;
        }
    }
    cout << ans;
    return 0;
}