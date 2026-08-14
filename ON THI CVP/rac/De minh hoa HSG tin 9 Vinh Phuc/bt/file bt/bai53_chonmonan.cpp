#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main()
{
    freopen("DISH.inp","r",stdin);
    freopen("DISH.out","w",stdout);
    ll n,p;
    cin >> n >> p;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    for(int i )
    return 0;
}
