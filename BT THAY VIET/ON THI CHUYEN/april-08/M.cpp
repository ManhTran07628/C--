#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int lcm(int a,int b)
{
    return a / __gcd(a,b)*b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    int ans = n/a + n/b - n/lcm(a,b);
    cout << ans;
    return 0;
}