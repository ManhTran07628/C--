#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int a[MM];


void solve()
{
    int n; cin >> n;
    map<int,int> f1,f2;
    vector<int> v;
    for(int i = 1;i <= n;i++) {
        cin >> a[i]; v.push_back(a[i]);
        if(i % 2 == 0) f1[ a[i] ]++;
        else f2[ a[i] ]++;
    }
    sort(a+1,a+n+1);
    int res = 0;
    for(int i = 1;i <= n;i++) {
        if(i % 2 == 0) f1[ a[i] ]--;
        else f2[ a[i] ]--;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(auto x:v) {
        if(f1[x] > 0) res += f1[x];
        if(f2[x] > 0) res += f2[x];
    }
    cout << res / 2 << '\n';
    
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}