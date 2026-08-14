#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y,n;
    cin >> x >> y >> n;
    int cost1 = x * n;
    int cost2 = (n / 3) * y + (n - n / 3 * 3) * x;
    cout << min(cost1,cost2);
    return 0;
}