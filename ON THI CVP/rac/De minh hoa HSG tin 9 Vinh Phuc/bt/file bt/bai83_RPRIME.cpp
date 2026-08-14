#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],c[N];
set<ll> ans;
ll dem[N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "RPRIME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(int i = 2;i < N;i++) 
        if(a[i] == 0)
            for(ll j = i;j < N;j+=i) 
                a[j]++;
    ll t;
    cin >> t;
    while(t--) {
        ll l,r,k;
        cin >> l >> r >> k;
        ll dem = 0;
        for(int i = l;i <= r;i++) 
            if(a[i] == k) dem++;
        cout << dem << '\n';
    }
    return 0;
}
