#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
pair<int,int> b[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "SDB"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n; cin >> n;
    
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        b[i] = {a,i};
    }
    sort(b+1,b+n+1);
    vector<pair<int,int>> v;
    for(int i = 1;i <= n;i++) {
        if(i == 1 && b[i].fi != b[i+1].fi) v.push_back(b[i]);
        if(i == n && b[i].fi != b[i-1].fi) v.push_back(b[i]);
        if(1 < i && i < n && b[i-1].fi != b[i].fi && b[i].fi != b[i+1].fi) v.push_back(b[i]);
    }
    sort(v.begin(),v.end(),[] (pair<int,int> a,pair<int,int> b){
        return a.se < b.se;
    });
    cout << v.size() << '\n';
    for(auto x:v) cout << x.fi << '\n';
    return 0;
}