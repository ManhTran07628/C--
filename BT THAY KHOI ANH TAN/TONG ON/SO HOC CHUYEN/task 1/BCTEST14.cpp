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
    double a,b,v;
    cin >> a >> b >> v;
    int x = ceil((v-b)/(a-b));
    cout << x;
    return 0;
}