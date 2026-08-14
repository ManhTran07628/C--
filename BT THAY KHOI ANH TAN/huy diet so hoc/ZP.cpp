#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 2e6+7;
int a[MAXN],p[MAXN];

void divisor_sieve()
{
    for(int i = 1;i < MAXN;i++)
        for(int j = i;j < MAXN;j+=i)
            p[j]++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    divisor_sieve();
    int n;
    cin >> n;
    int ans = 2;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ans = max(ans,p[a[i]]);
    }
    cout << ans;
    return 0;
}