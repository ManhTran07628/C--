#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
ll MOD = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a[1] = 1;
    a[2] = 1;
    for(int i = 3;i <= n;i++) {
        a[i] = (a[i-2]%MOD+a[i-1]%MOD)%MOD;
    }
    cout << a[n];
    return 0;
}