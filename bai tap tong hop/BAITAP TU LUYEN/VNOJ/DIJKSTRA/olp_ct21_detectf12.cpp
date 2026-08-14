#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,ll>
const int MM = 1e3 + 7;
ll n,F0,D,x[MM],y[MM],isF1[MM],isF2[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> F0 >> D;
    for(int i = 1;i <= n;i++) {
        cin >> x[i] >> y[i];
    }
    int F1 = 0,F2 = 0;
    queue<int> q;
    q.push(F0);
    
    cout << F1 << ' ' << F2;
    return 0;
}