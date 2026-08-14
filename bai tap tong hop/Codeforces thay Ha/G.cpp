#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
ll n,a[MM],b[MM],prefixmax[MM],suffixmax[MM],T[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        T[i] = T[i-1] + b[i];
        prefixmax[i] = max(prefixmax[i-1],a[i]-T[i-1]);
    }
    for(int i = n;i >= 1;i--) {
        suffixmax[i] = max(suffixmax[i+1],a[i]-T[i-1]);
    }
    ll k = oo;
    for(int i = 1;i <= n;i++) {
        ll tmp = max(suffixmax[i]+T[i-1],prefixmax[i]-(T[n]-T[i-1]));
        k = min(k,tmp);
    }
    cout << k;
    return 0;
}