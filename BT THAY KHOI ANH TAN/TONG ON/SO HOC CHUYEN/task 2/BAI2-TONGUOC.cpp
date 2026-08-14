#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int cntdivs[MAXN],n;
bool isprime(int k)
{
    if(k < 2) return 0;
    for(int i = 2;i*i <= k;i++)
        if(k % i == 0) return 0;
    return 1;
}

void sub12()
{
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int sum = 0;
        for(int j = 1;j*j <= i;j++) {
            if(i % j == 0) {
                sum += j;
                if(i / j != j) sum += i/j;
            }
        }
        if(isprime(sum)) cout << i << ' ' << sqrt(i) << ' ' << sum << '\n';
    }
    // cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sub12();
    return 0;
}