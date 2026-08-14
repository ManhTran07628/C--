#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tamgiac"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll ans = 0,count = 0;
    for(int i = 1;i <= 2001;i++) {
        if(b[i] >= 3) {
            ans += b[i] / 3;
            count += b[i] / 3 * 3;
        }
    }
    cout << ans << " " << n - count;
    return 0;
}