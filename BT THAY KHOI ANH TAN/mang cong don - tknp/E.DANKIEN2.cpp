#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        p[i] = p[i-1]+a[i];
    }
    for(int i = 1;i <= n;i++) {
        ll phai = (p[n]-p[i]-(n-i)*a[i]);
        ll trai = a[i]*i-p[i];
        cout << phai+trai << ' ';
    }
    return 0;
}