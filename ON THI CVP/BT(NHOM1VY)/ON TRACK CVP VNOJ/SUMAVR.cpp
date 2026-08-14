#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],b[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll x = 0;
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        cout << b[i]*i - (b[i-1]*(i-1)) << ' ';
    }
    return 0;
}