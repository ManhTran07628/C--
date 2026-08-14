#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0,cnt = 0;
    for(ll i = 1;i <= sqrt(n);i++) {
        if(i % 2 != 0) {
            ans += i*i;
            cnt++;
        }
    }
    cout << cnt << '\n' << ans;
    return 0;
}