#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
map<ll,ll> b;
ll a[N];
int main()
{
    freopen("muaqua.inp","r",stdin);
    freopen("muaqua.out","w",stdout);
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        if(b[a[i]] == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}


