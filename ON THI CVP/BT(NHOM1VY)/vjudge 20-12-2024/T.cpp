#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N];
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
        l[a[i]] = i;
        r[a[i]] = n-i+1;
    }
    ll p = 0,v = 0;
    ll q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        p += l[x];
        v += r[x];
    }
    cout << p << ' ' << v;
    return 0;
}