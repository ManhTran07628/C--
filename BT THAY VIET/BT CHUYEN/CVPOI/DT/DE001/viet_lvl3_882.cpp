#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e4 + 7;
int m,n,a[MM],cnts1[MM],cnts2[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> m >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    int k = n / 2;

    for(int i = 1;i <= k;i++) cnts1[ a[i] ]++;
    for(int i = k + 1;i <= k * 2;i++) cnts2[ a[i] ]++;

    while(k > 0) {
        int cs1 = 0,cs2 = 0,ok = 1;
        for(int x = 1;x <= m;x++) {
            cs2 += cnts2[x];
            if(cs2 > cs1) {
                ok = 0;
                break;
            }
            cs1 += cnts1[x];
        }
        if(ok) {
            cout << k;
            return 0;
        }

        if(k > 1) {
            cnts1[ a[k] ]--;
            cnts2[ a[k*2] ]--;
            cnts2[ a[k*2-1] ]--;
            cnts2[ a[k] ]++;
        }
        k--;
    }
    return 0;
}