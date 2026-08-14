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
    ll a,b;
    cin >> a >> b;
    ll a1 = a,b1 = b;
    if(a % 2 != 0) a++;
    if(a % 3 == 0 || a1 == a) a+=2;
    if(b % 2 != 0) b--;
    if(b % 3 == 0 || b1 == b) b-=2;
    int s1 = (b-a)/2;
    int s2 = (b-a)/6;
    a1 = (a1-1)/2*2;
    b1 = (a)
    cout << s1 << ' ' << s2 << '\n';
    ll ans = (b+a)*s1/2 - (b+a)*s2/2;
    cout << ans;
    return 0;
}