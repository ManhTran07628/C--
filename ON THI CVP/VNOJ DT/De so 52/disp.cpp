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
    #define taskname "disp"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    ll a,b,min1 = 1e9;
    cin >> n;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            if(abs((n/i)-i) < min1) {
                a = i;
                b = n/i;
            }
        }
    }
    cout << a << ' ' <<  b;
    return 0;
}