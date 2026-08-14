#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,a[MM];
set<pair<int,pii>> mp;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "triangles"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            int k = lower_bound(a+j,a+n+1,a[i] + a[j]) - a - 1;
            if(a[i] + a[k] > a[j] && a[i] + a[j] > a[k] && a[k] + a[j] > a[i]) {
                for(int d = j+1;d <= k;d++)
                    mp.insert({a[i],{a[j],a[d]}});
            }
        }
    }
    // for(auto x:mp) cout << x.fi << ' ' << x.se.fi << ' ' << x.se.se << '\n';
    cout << mp.size();
    return 0;
}

// a + b > c    b + c > a