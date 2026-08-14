#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int maxdigit(int k)
{
    int digit = 0;
    while(k > 0) {
        digit = max(digit,k%10);
        k /= 10;
    }
    return digit;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    while(n > 0) {
        n -= maxdigit(n);
        cnt++;
    }
    cout << cnt;
    return 0;
}