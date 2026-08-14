#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n;
int a[MAXN];

int cnt(int x)
{
    int sum = 0;
    for(int i = 1;i <= n;i++) {
        sum += abs(a[i]-x);
    }
    return sum;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = min(cnt(a[(n+1)/2]),cnt(a[(n+1)/2+1]));
    cout << ans;
    return 0;
}