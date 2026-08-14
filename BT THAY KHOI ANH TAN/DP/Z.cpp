#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dpa[MAXN],dpb[MAXN],dpc[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dpa[1] = a[1];
    dpb[1] = b[1];
    dpc[1] = c[1];
    for(int i = 2;i <= n;i++) {
        dpa[i] = max(dpb[i-1],dpc[i-1])+a[i];
        dpb[i] = max(dpa[i-1],dpc[i-1])+b[i];
        dpc[i] = max(dpa[i-1],dpb[i-1])+c[i];
    }
    cout << max({dpa[n],dpb[n],dpc[n]});
    return 0;
}