#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N],f[N];



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "somu"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        ll dem = 0;
        while(n >= k) {
            n /= k;
            dem += n;
        }
        cout << dem << '\n';
    }
    return 0;
}