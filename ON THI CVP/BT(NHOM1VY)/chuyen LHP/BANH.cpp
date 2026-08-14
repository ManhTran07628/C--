#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double n,m,k;
    cin >> n >> m >> k;
    double ans = 1e9;
    if(n >= k) ans = n*m*0.8;
    else ans = min(n*m,k*m*0.8);
    cout << ans;
    return 0;
}