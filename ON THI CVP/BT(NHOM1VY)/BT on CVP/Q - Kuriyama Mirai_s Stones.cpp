#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        a[i] = a[i-1] + a[i];
        b[i] = b[i-1] + b[i];
    }
    ll q;
    cin >> q;
    while(q--) {
        ll t,l,r;
        cin >> t >> l >> r;
        if(t == 1) cout << b[r] - b[l-1] << '\n';
        else cout << a[r] - a[l-1] << '\n';
    }
    return 0;
}