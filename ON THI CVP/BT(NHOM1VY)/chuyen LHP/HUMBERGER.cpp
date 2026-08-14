#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
bool check(ll s,ll m,ll n,ll k,ll r,ll cpB,ll cpX,ll cpP,ll t1,ll t2,ll t3)
{
    ll chiphi = 0;
    ll nlB = s * cpB - m;
    ll nlX = s * cpX - n;
    ll nlP = s * cpP - k;
    if(nlB > 0) chiphi += nlB*t1;
    if(nlX > 0) chiphi += nlX*t2;
    if(nlP > 0) chiphi += nlP*t3;
    return chiphi <= r;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t1,t2,t3;
    ll m,n,k,r;
    string s;
    while(cin >> s >> m >> n >> k >> t1 >> t2 >> t3 >> r) 
    {
        ll cpB = 0,cpX = 0,cpP = 0;
        for(auto i:s) {
            if(i == 'B') cpB++;
            if(i == 'X') cpX++;
            if(i == 'P') cpP++;
        }
        ll L = 0,R = 1e6,ans = 0;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(check(mid,m,n,k,r,cpB,cpX,cpP,t1,t2,t3)) {
                ans = mid;
                L = mid + 1;
            }
            else R = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}