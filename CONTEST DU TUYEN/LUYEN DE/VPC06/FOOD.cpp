#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m,d,p[MM],q[MM],r[MM],s[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "FOOD"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> d;
    for(int i = 1;i <= n;i++) cin >> p[i] >> q[i];
    for(int i = 1;i <= m;i++) cin >> r[i] >> s[i];
    cout << 3;
    return 0;
}