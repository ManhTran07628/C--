#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int prefix[MAXN],suffix[MAXN];
int a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];


    prefix[1] = a[1];
    suffix[n] = a[n];
    for(int i = 2;i <= n;i++) prefix[i] = __gcd(prefix[i-1],a[i]);
    for(int i = n-1;i >= 1;i--) suffix[i] = __gcd(suffix[i+1],a[i]);
    int ans = 1;
    for (int i = 1;i <= n-k+1;i++) {
        int left = (i > 1) ? prefix[i - 1] : 0;
        int right = (i + k <= n) ? suffix[i + k] : 0;
        ans = max(ans, __gcd(left, right));
    }
    cout << ans;

    return 0;
}


// 2 4 3 5 6
