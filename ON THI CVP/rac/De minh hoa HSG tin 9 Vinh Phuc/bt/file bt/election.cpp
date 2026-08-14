#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "election"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    sort(a+1,a+n+1,greater<ll>());
    if(m == 1) {
        cout << 0;
        return 0;
    }ll dem =0;
    for(int i = 1;i <= n;i++) {
        if(dem + a[i]-1>= m) {
            cout << i;
            return 0;
        }
        dem += a[i]-1;
    }
    cout << -1;
    return 0;
}