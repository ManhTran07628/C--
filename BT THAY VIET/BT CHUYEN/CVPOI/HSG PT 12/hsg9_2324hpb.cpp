#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q,a[MM];

bool check(int k)
{
    int d = k,sum = 0;
    while(d > 0) {
        sum += d % 10;
        d /= 10;
    }
    return k % sum == 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = check(a[i]);
        a[i] += a[i-1];
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}