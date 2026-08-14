#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll n,m,j;
    cin >> n >> m >> j;
    for(ll i = 1;i <= n;i++) {
        ll i1 = i - 1;
        ll d = 1 + ((i1*i1) % m); 
        b[i] = b[i-1] + d;
    }
    ll l = 1,r = b[n],max1 = 1e9;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll ans = 0,kt = 1,k = 0;
        for(int i = 1;i <= n;i++) {
            if(b[i] - b[k-1] > mid) {
                k = i - 1;
                
            }
        }

    }
    return 0;
}