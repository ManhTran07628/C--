#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll l,r;
    cin >> l >> r;
    ll max1 = 0;
    for(ll i = l;i < r;i++) {
        if(r-i <= max1) break;
        for(ll j = r;j > i;j--) {
            if(j-i <= max1) break;
            if(__gcd(i,j) == 1) {
                max1 = max(max1,j-i);
                break;
            }
        }
    }
    cout << max1;
    return 0;
}