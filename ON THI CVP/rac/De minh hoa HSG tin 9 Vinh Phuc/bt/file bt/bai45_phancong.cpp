#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N],c[N];
int main()
{
    freopen("PHANCONG.inp","r",stdin);
    freopen("PHANCONG.out","w",stdout);
    ll m,n,k;
    ll min1 = 1e9;
    for(int i = 1;i <= 3;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1;i <= 3;i++) {
        for(int j = 1;j <= 3;j++) {
            for(int h = 1;h <= 3;h++) {
                ll tmp = max(a[i],max(b[j],c[h]));
                min1 = min(min1,tmp);
            }
        }
    }
    cout << min1;
    return 0;
}


