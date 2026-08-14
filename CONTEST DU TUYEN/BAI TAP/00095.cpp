#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e4+7;
int n;
pair<int,int> a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1, [] (pii a, pii b){
        if(a.fi != b.fi) return a.fi > b.fi;
        return a.se < b.se;
    });

    int res = 0;
    while(1) {

        bool ok = 1;
        for(int i = 1;i <= n;i++) {
            if(a[i].fi == 0) continue;
            ok = 0;
        }
        if(ok) break;

        

    }

    for(int i = 1;i <= n;i++) {
        cout << a[i].fi << ' ' << a[i].se << '\n';
    }

    return 0;
}