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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    while(q--) {
        ll l,r;
        cin >> l >> r;
        ll pd = lower_bound(a+1,a+n+1,l)-a;
        ll pl = upper_bound(a+1,a+n+1,r)-a;
        cout << pl - pd << '\n';
    }
    return 0;
}