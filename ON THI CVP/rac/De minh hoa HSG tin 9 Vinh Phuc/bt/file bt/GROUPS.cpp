#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("GROUPS.inp","r",stdin);
   // freopen("GROUPS.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll i = 1,j = 1,dem = 0;
    while(j <= n) {
        ll ans = abs(a[j] - a[i]);
        if(ans <= k) {
            j++;
        }
        else if(ans > k || j == n){
            dem++;
            i = j;
            break;
        }
    }
    cout << dem+1;
    return 0;
}





