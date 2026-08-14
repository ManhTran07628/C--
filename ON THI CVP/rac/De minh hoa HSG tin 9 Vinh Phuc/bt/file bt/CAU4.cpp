#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

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
    ll n,k,s;
    cin >> n >> k >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        ll vtd = lower_bound(b+1,b+n+1,s-b[i]) - b;
        double dau = floor(double(vtd)/k);
        double cuoi = ceil(double(n) / k);
        ll d = dau;
        ll c = cuoi;
        dem += (cuoi - dau) / k; 
    }
    cout << dem;
    return 0;
}