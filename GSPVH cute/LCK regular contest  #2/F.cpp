#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,ans[MM],Next[MM],id1 = 0, id2 = 0, existA[MM],existB[MM];
pii a[MM];
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
    vector<int> vec;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi != 0 && a[i].se != 0) {
            Next[ a[i].fi ] = a[i].se;
        }
        if(a[i].fi == 0) {
            id2 = a[i].se;
        }
        existA[ a[i].fi ] = 1;
        existB[ a[i].se ] = 1;
    }

    for(int i = 1;i <= n;i++) {
        if(existA[ a[i].fi ] && !existB[ a[i].fi ]) {
            id1 = a[i].fi;
            break;
        }
    }

    for(int i = 1;i <= n;i += 2) {
        ans[i] = id1;
        id1 = Next[id1];
    }

    for(int i = 2;i <= n;i += 2) {
        ans[i] = id2;
        id2 = Next[id2];
    }

    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';


    return 0;
}