#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}