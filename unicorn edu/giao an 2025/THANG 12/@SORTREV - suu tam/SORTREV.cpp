#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
vector<int> v,b;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        v.push_back(a);
        b.push_back(a);
    }
    sort(v.begin(),v.end());
    reverse(b.begin(),b.end());
    for(auto x:v) cout << x << ' ';
    cout << '\n';
    for(auto x:b) cout << x << ' ';
    return 0;
}