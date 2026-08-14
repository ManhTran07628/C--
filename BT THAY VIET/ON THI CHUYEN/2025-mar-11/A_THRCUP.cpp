#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<int,int> a[4];
int kt[4];
int main() // 1-2   2-3   1-3
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    for(int i = 1;i <= 3;i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].se = a[i].fi-a[i].se*2;
    }
    sort(a+1,a+4);
    ans = a[3].fi;
    if(a[2].fi <= a[3].se) {
        if(a[1].fi <= a[2].se) ans += 0;
        else if(a[3].se-a[2].fi >= a[1].fi) ans += 0;
        else ans += a[1].fi;
    }
    else if(a[2].fi > a[3].se && (a[1].fi <= a[3].se || a[1].fi <= a[2].se)) ans += a[2].fi;
    else ans += a[2].fi + a[1].fi;
    cout << ans;
    return 0;
}