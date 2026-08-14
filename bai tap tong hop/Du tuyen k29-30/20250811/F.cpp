#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;

int maxdigit(int a)
{
    int ans = 0;
    while(a > 0) {
        ans = max(ans,a%10);
        a /= 10;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt = 0;
    cin >> n;
    while(n > 0) {
        cnt++;
        n -= maxdigit(n);
    }
    cout << cnt;
    return 0;
}