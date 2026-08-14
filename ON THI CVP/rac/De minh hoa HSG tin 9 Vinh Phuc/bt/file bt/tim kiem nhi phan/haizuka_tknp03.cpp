#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;

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
    ll a,b,n;
    cin >> a >> b >> n;
    ll l = 1,h = 1e9,ans = 0;
    while(l <= h) {
        ll mid = (l+h)/2;
        ll sum = mid + (mid / a) * b;
        if(sum >= n) {
            h = mid - 1;
        }
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
