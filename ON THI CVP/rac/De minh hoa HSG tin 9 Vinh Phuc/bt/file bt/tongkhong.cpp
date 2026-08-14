#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
map<ll,ll> b;

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
    ll n,tong = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    b[0] = 1;
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        tong += a[i];
        dem += b[tong];
        b[tong]++;
    }
    cout << dem;
    return 0;
}