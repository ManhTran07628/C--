#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n;
int a1,a2,a3,b1,b2,b3;  

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
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
    int res = min(a1,b2) + min(a2,b3) + min(a3,b1);
    cout << res;
    return 0;
}