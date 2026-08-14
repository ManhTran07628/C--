#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define taskname "TBC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    b[0] = 1;
    ll dem = 0,tong = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tong += a[i];
        dem += b[tong-k*i];
        b[tong-k*i]++;
    }
    cout << dem;
    return 0;
}

