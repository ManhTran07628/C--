#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
ll n;
ll cm = 1e9;
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = 1;
    ll L = 1,R = 1e9;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll min1 = 1e9;
        for(ll i = max(1ll,mid-100);i <= mid+100;i++) {
            ll ans = 0,kt = 1,count = 1;
            for(int j = 1;j <= n;j++) {
                if(ans + a[j] < i) {
                    ans += a[j];
                }
                else if(ans + a[j] == i) {
                    ans = 0;
                    count++;
                }
                else if(ans + a[j] > i){
                    kt = 0;
                    break;
                }
            }
            if(kt) {
                min1 = min(min1,count);
            }
        }
        if(min1 != cm) {
            ans = min1;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}