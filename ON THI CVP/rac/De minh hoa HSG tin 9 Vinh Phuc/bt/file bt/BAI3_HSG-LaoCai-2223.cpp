#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<ll,ll> b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAPPT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k,dem = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dem += b[k-a[i]];
        b[a[i]]++;
    }
    cout << dem;
    return 0;
}
