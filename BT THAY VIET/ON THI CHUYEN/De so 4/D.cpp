#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ull unsigned long long
const int N = 1e6+7;
ll n,m,k;

ull lcm(ull a,ull b)
{
    return a / __gcd(a,b) * b;
}

ull check(ull k)
{
    return k / n + k / m - k / lcm(n,m)*2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> k;
    ull l = 1,r = 1e18,ans = 0;
    while(l <= r) {
        ull mid = (l+r)/2;
        if(check(mid) >= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}