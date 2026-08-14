#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sub"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll min1 = 1e9,ktra = 0;
    for(int i = 1;i <= n;i++) {
        ll L = 1,R = n,vtmin = 0;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(b[mid] - b[i-1] >= s) {
                vtmin = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        if(vtmin != 0) {
            min1 = min(vtmin-i+1,min1);
            ktra = 1;
        }
    }
    if(ktra) cout << min1;
    else cout << 0;
    return 0;
}