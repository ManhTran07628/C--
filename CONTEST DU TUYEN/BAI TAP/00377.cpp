#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int T,n,a[MM],pf[MM],sf[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> T >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    int l1 = 1,r1 = n;
    for(int i = 1;i <= n;i++) {
        if(!pf[ a[i] ]) pf[ a[i] ] = 1;
        else {
            l1 = i;
            break;
        }
    }

    int l2 = 1, r2 = n;
    for(int i = n;i >= 1;i--) {
        if(!sf[ a[i] ]) sf[ a[i] ] = 1;
        else {
            r2 = i;
            break;
        }
    }
    
    // cout << l1 - 1 << ' ' << l2 << '\n';

    int l3 = 1,r3 = 1e9;
    for(int i = l1 - 1, j = n;i >= 1 && i <= j;) {
        if(!pf[ a[j] ]) {
            pf[ a[j] ]++;
            j--;
        }
        else {
            while(i >= 1 && pf[ a[j] ] == 1) {
                pf[ a[i] ]--;
                i--;
            }
        }

        if(pf[ a[j] ] <= 1) {
            if(j - i < r3 - l3 + 1) {
                l3 = i, r3 = j - 1;
            }
        }
    }
    // cout << l3 << ' ' << r3 << '\n';

    int val = min({r3 - l3 + 1,r2 - l2 + 1,r1 - l1 + 1});

    if(val == r1 - l1 + 1) cout << l1 - 1 << ' ' << r1 - 1;
    else if(val == r2 - l2 + 1) cout << l2 - 1 << ' ' << r2 - 1;
    else if(val == r3 - l3 + 1) cout << l3 << ' ' << r3 ;

    return 0;
}