#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    int d1 = min({a,b,c});
    int d3 = max({a,b,c});
    int d2 = a+b+c-d3-d1;
    if(d1 == d2 || d2 == d3 || d3 == d1) cout << -1;
    else {
        if(d1+1 == d2 && d2+1 == d3 ) cout << d1 << ' ' << d2 << ' ' << d3;
        else cout << -1;
    }
    return 0;
}