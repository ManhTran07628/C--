#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


void sub1(ll a,ll b)
{
    ll c=b;
    while (__gcd(a,c)==1) {
        c++;
    }
    cout<<c-b<<"\n";
}

ll solve(ll a,ll b)
{
    ll ans = 1e9;
    for(ll i = 1;i*i <= a;i++) {
        if(a % i == 0) {
            if(i != 1) {
                ll x = ceil(double(b)/i)*i;
                if(x >= b)
                    ans = min(ans,x-b);
            }
            if(a / i != i) {
                ll j = a / i;
                ll x = ceil(double(b)/j)*j;
                if(x >= b)
                    ans = min(ans,x-b);
            }
        }
    }
    return ans;
}

void sub2(ll a,ll b)
{

    if(solve(a,b) == 0) {
        cout << 0 << '\n';
    }
    else cout << solve(a,b) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "door"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        if(a <= 1e6 && b <= 1e6) sub1(a,b);
        else sub2(a,b);
    }
    return 0;
}