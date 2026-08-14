#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main()
{
    ll n,l,r;
    cin >> n >> l >> r;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        ll dau = i+1,cuoi = n-1,vtd = 0,vtc = 0;
        while(dau <= cuoi) {
            ll mid = (dau+cuoi)/2;
            if(a[i] + a[mid] >= l) {
                vtd = mid;
                cuoi = mid - 1;
            } 
            else {
                dau = mid + 1;
            }
        }
        dau = i+1,cuoi = n-1;
        while(dau <= cuoi) {
            ll mid = (dau+cuoi)/2;
            if(a[i] + a[mid] <= r) {
                vtc = mid;
                dau = mid + 1;
            } 
            else {
                cuoi = mid - 1;
            }
        }
        if(vtd <= vtc && vtc != 0 && vtc != 0)
            dem += vtc - vtd + 1;
    }
    cout << dem;
    return 0;
}
