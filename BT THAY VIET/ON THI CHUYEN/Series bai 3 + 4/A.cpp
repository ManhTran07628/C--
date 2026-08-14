#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];

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
    ll n,t;
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll crr = 0,ans = 0;
    ll i = 1,j = 1;
    while(i <= n && j <= n) {
        if(crr + a[j] <= t) {
            crr += a[j];
            j++;
        }
        else {
            crr -= a[i];
            i++;
        }
        ans = max(ans,j-i);
    }
    cout << ans;
    return 0;
}