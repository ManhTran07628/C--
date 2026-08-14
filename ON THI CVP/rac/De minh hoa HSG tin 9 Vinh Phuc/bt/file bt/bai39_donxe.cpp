#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main()
{
    freopen("DONXE.inp","r",stdin);
    freopen("DONXE.out","w",stdout);
    ll n;
    cin >> n;
    ll min1 = 1e9;
    for(int i = 0;i < n;i++) {
        cin >> a[i] >> b[i];
        if(a[i] + b[i] + 1 <= 60 && a[i] + b[i] + 1 >= 50) {
            min1 = min(min1,a[i] + b[i] + 1);
        }
    }
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] + b[i] + 1 == min1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}
