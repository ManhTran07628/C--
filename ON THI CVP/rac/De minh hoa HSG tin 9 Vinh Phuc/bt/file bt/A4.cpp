#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
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
    long double ans = 0;
    ll n,cnt = 0;
    while(cin >> n) {
        ans+=n;
        cnt++;
    }
    ans = ans / cnt;
    cout << fixed << setprecision(6) << ans;
    return 0;
}