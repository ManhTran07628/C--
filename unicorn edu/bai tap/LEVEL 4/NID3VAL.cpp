#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,d[MM],a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> d[i];
        a[i] = d[i];
    }

    int res1 = 0,res2 = 0;
    // decrease
    for(int i = 2;i <= n;i++) {
        if(d[i-1] >= d[i]) continue;
        else {
            d[i-1] = d[i];
            res1++;
        }
    }
    // increase
    for(int i = 2;i <= n;i++) {
        if(a[i-1] <= a[i]) continue;
        else {
            a[i] = a[i-1];
            res2++;
        }
    }
    cout << min(res1,res2);
    return 0;
}