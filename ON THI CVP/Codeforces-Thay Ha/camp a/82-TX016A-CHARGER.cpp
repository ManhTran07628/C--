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
    ll n,x;
    cin >> n >> x;
    ll ans = n;
    for(int i = 1;i <= 3;i++) {
        ll a;
        cin >> a;
        ans = min(ans,abs(a-x));
        ans = min(ans,abs((a+n)-x));
        if(x == 0) {
            ans = min(ans,abs(n-a));
        }
    }
    cout << ans;
    return 0;   
}