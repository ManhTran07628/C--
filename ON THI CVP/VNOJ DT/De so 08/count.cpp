#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "count"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,x,q;
    cin >> n >> x >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        b[i] = b[i-1];
        if(a[i] > 0 && a[i] < x) {
            b[i]++;
        }
    }
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << b[r]-b[l-1] << '\n';
    }
    return 0;
}