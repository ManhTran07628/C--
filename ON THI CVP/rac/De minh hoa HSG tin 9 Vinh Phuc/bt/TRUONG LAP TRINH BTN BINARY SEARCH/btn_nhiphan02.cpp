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
    while(q--)
    {
        ll x;
        cin >> x;
        ll posfi = lower_bound(a+1,a+n+1,x) - a;
        ll poslt = upper_bound(a+1,a+n+1,x) - a;
        cout << poslt - posfi << '\n';
    }
    return 0;
}