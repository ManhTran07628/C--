#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<int> v;
    for(int i = 1;i <= n;i++) {
        int pos = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
        if(pos == v.size()) v.push_back(a[i]);
        else v[pos] = a[i];
    }
    cout << v.size() << '\n';
    for(auto x:v) cout << x << ' ';
    return 0;
}