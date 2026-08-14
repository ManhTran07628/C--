#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "COVID19"
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
        for(int i = 1;i <= n;i++) 
            cin >> a[i];
        ll i = 1,j = 1;
        ll min1 = n,max1 = 1;
        for(int i = 0; i < n; i++) {
            ll dem = 1;
            ll l = i, r = i;
            while (l > 0 && a[i] - a[l - 1] <= 2) {
                dem++;
                l--;
            }
            while (r < n - 1 && a[r + 1] - a[i] <= 2) {
                dem++;
                r++;
            }
            min1 = min(min1, dem);
            max1 = max(max1, dem);
        }
        cout << min1 << " " << max1 << '\n';
    }
    return 0;
}