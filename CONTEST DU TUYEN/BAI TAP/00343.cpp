#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,a[MM],b[MM];

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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    vector<pii> v;
    for(int i = 1;i <= n;i++) {
        v.push_back({(int) min(a[i],b[i]),(int) max(a[i],b[i])});
    }
    sort(v.begin(),v.end());
    bool ok = 1;
    for(int i = 1;i < v.size();i++) {
        if(v[i].se < v[i-1].se) {
            ok = 0;
            break;
        }
    }
    if(!ok) cout << -1;
    else {
        for(auto x:v) cout << x.fi << ' '; cout << '\n';
        for(auto x:v) cout << x.se << ' '; 
    }
    return 0;
}