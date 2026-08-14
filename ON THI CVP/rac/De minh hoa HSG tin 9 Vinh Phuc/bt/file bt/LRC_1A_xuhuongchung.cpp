#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],c[N];
map<ll,ll> b;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "chiak"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ll ans = (a[i]%k+k)%k; // xử lí số âm
        c[i] = ans;
        c[i] = (c[i-1] + c[i])%k;
    }
    b[0] = 1;
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        dem += b[c[i]];
        b[c[i]]++;
    }
    cout << dem;
    return 0;
}