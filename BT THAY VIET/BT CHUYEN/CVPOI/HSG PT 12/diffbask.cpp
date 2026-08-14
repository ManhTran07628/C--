#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    int h = k;
    if(n < k * (k + 1) / 2) {
        cout << -1;
        return 0;
    }
    int i = 1;
    while(n > 0) {
        int cur = k * (k + 1) / 2;
        if(n >= cur) {
            for(int j = i;j <= h;j++) a[j]++;
            n -= k;
        }
        else {
            k--;
            i++;
        }
    }
    cout << abs(a[1] - a[h]);
    // for(int i = 1;i <= h;i++) cout << a[i] << ' ';
    return 0;
}