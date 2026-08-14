#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main()
{
    freopen("CHONGOI.inp","r",stdin);
    freopen("CHONGOI.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    ll vtle = n/2+1,j = 0,ans = 1;
    ll vtchan = n/2-1;
    a[n/2] = 1;
    ll i = 2;
    while(i <= n) {
        if(ans % 2 != 0) {
            while(j < 2 && i <= n) {
                a[vtle] = i;
                vtle++;
                j++;
                i++;
            }
            j = 0;
            ans++;
        }
        else {
            while(j < 2 && i <= n) {
                a[vtchan] = i;
                vtchan--;
                j++;
                i++;
            }
            j = 0;
            ans++;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] == k) {
            cout << i;
            return 0;
        }
    }
    return 0;
}

