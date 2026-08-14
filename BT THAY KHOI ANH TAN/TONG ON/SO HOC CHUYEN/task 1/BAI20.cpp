#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a,b,c,d;

int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

void solve()
{
    int mauso = lcm(b,d);
    a = a * (mauso / b);
    c = c * (mauso / d);
    int tuso = __gcd(a,c);
    int d = __gcd(tuso,mauso);
    tuso /= d;
    mauso /= d;
    cout << tuso << ' ' << mauso;
}   

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    solve();
    return 0;
}