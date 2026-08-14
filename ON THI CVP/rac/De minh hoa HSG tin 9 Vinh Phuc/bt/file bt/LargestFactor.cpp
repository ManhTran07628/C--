#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "LargestFactor"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll max1 = 0;
        for(int i = 2;i <= sqrt(n);i++) {
            while(n % i == 0) {
                max1 = i;
                n /= i;
            }
        }
        if(n > 1) max1 = n;
        cout << max1 << '\n';
    }
    return 0;
}