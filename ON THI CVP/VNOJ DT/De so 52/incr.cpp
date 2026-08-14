#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "incr"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,d;
    cin >> n >> d;
    ll cnt = 0;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    for(int i = 1;i < n;i++) {
        if(a[i+1] <= a[i]) {
            ll t = ceil((double)(a[i] - a[i+1]+1) / d);
            cnt += t;
            a[i+1] += t*d;
        }
    }
    // for(int i = 1;i <= n;i++) {
    //     cout << a[i] << ' ';
    // }
    cout << cnt;
    return 0;
}