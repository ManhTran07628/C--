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
    int x,y,n;
    cin >> x >> y >> n;
    int cost = 10*n/(x*9+y);
    cout << cost;
    return 0;
}