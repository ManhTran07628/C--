#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int lcm(int a,int b)
{
    return a / __gcd(a,b) * b;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    if(a > b) swap(a,b);
    int ans = 0;
    ans += min(n,a-1);
    int L = lcm(a,b);
    int freq = n / L;
    int h = freq * L;
    ans += freq*a;
    ans = ans - ((h+a-1)-max(h,min(h+a-1,n)));
    cout << ans;
    return 0;   
}