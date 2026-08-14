#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<ll,ll> p[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= n;i++) {
        cin >> p[i].fi >> p[i].se;
    }
    int days = 0,minute = 0;
    for(int i = 1;i <= n;i++) {
        int d1 = p[i].fi*m, d2 = p[i].fi*p[i].se;
        
    }
    return 0;
}