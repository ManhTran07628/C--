#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 7;
ll n;
ll a[N];
ll solve(ll k)
{
    ll cnt = 0,sum = 0;
    for(int i = 1;i <= n;i++) {
        sum += a[i];
        if(sum == k) {
            sum = 0;
        }
        else if(sum > k) {
            return -1;
        }
        else if(sum < k) cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("EVOLVE.inp","r",stdin);
    // freopen("EVOLVE.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll L = 1,R = 1e15,crr = n;
    while(L <= R) {
        ll mid = (L+R) / 2;
        if(crr >= solve(mid) && solve(mid) != -1) {
            crr = min(solve(mid),crr);
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << crr;
    return 0;
}
