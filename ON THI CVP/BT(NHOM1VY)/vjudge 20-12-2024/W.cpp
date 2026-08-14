#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N],p1[N],p2[N];

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
        p1[i] = p1[i-1] + a[i];
    }
    sort(b+1,b+n+1);
    for(int i = 1;i <= n;i++) {
        p2[i] = p2[i-1] + b[i];
    }
    ll q;
    cin >> q;
    while(q--) {
        ll x,l,r;
        cin >> x >> l >> r;
        if(x == 1) cout << p1[r] - p1[l-1];
        else cout << p2[r] - p2[l-1];
        cout << '\n';
    }
    return 0;
}