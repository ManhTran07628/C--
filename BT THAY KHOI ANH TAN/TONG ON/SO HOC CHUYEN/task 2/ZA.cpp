#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n;

int lcm(int a,int b)
{
    return a/__gcd(a,b)*b;
}

void solve()
{
    for(int i = n/2;i >= 1;i--) {
        if(__gcd(i,n-i) == 1) {
            cout << lcm(i,n-i);
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();    x
    return 0;
}