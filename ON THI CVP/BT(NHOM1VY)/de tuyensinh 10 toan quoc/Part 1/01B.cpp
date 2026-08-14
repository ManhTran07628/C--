#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<ll> d,v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        ll a,b;
        cin >> a >> b;
        d.push_back(a);
        v.push_back(b);
    }
    sort(d.begin(),d.end());
    sort(v.begin(),v.end(),greater<ll>());
    ll ans = d[0];
    for(int i = 1;i < d.size();i++) {
        ans += (d[i]-d[i-1]);
    }
    ans += abs(d[d.size()-1]-v[0]);
    for(int i = 1;i < v.size();i++) {
        ans += abs(v[i]-v[i-1]);
    }
    cout << ans + (m-v[v.size()-1]);
    return 0;
}