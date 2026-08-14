#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int NN = 1e6+7;
ll a,b,N;

ll lcm(ll a,ll b)
{
    return a * __gcd(a,b) / b;
}

ll check(ll k)
{
    ll ab = lcm(a,b);
    return k / a + k / b - (k/ab);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> N;
        ll L = 1,R = 1e9,ans = 0;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(check(mid) < N) {
                L = mid + 1;
            }
            else if(check(mid) > N) {
                R = mid - 1;
            }
            else {
                while(mid % a != 0 && mid % b != 0) mid++;
                ans = mid;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}