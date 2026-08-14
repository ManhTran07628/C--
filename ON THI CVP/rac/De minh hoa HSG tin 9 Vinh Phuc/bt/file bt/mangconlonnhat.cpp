#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];
int main()
{
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        ll L = i,R = n,vt = -1;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(b[mid] - b[i-1] >= k) {
                vt = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        if(vt != -1) {
            dem += (n - vt + 1);
        }
    }
    cout << dem;
    return 0;
}

