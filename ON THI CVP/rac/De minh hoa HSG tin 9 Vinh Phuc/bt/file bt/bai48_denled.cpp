#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main()
{
    freopen("LED.inp","r",stdin);
    freopen("LED.out","w",stdout);
    ll t,n,k;
    cin >> t >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll soden = 0,max1 = -1e9,dem = 0,ll d = 0,c = 0;
    ll i = 0,j = 1;
    while(j <= n) {
        if(j - i + 1 > k) {
            i++;
        }
        d = a[]
    }
    cout << max1;
    return 0;
}
