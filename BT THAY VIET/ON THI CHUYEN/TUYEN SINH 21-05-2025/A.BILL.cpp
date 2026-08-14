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
    int n;
    cin >> n;
    int ans = 0;
    if(1 <= n && n <= 100) ans = n*10;
    if(101 <= n && n <= 200) ans = 100*10+(n-100)*15;
    if(201 <= n && n <= 300) ans = 100*10+15*100+(n-200)*20;
    if(301 <= n) ans = 100*10+15*100+20*100+(n-300)*25;
    cout << ans;
    return 0;
}