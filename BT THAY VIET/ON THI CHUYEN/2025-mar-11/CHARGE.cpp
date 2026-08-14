#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,p;
    cin >> n >> p;
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1,a+4);
    ll ans = 1e15;
    for(int i = 1;i <= 3;i++) {
        ans = min({ans,abs(a[i] - p), n - abs(a[i] - p)});

    }
    cout << ans;
    return 0;
}