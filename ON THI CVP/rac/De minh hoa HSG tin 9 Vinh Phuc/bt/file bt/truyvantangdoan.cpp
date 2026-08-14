#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
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
    while(q--) {
        ll l,r,k;
        cin >> l >> r >> k;
        a[l] += k;
        a[r+1] -= k;
    }
    for(int i = 1;i <= n;i++) {
        a[i] = a[i-1] + a[i];
        cout << a[i] << " ";
    }
    return 0;
}