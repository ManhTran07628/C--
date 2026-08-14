#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,a[MM];

ll is_Lower(ll X1,ll Y1,ll X2,ll Y2)
{
    return X1 * Y2 < X2 * Y1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int Upper = a[1] + a[n], Lower = 2;
    sort(a+2,a+n);

    for(int i = 2;i <= n - 1;i++) {
        int new_Upper = Upper + a[i];
        int new_Lower = Lower + 1;
        if(is_Lower(Upper,Lower,new_Upper,new_Lower)) break;
        Upper = new_Upper;
        Lower = new_Lower;
    }

    cout << fixed << setprecision(3) << (double) Upper / Lower;

    return 0;
}