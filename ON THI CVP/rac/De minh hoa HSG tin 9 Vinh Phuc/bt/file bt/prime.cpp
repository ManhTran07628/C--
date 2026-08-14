#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll l,r;
void sang()
{
    ll a[r-l+1];
    for(int i = l;i <= r;i++) 
        a[i-l] = 1;
    for(ll i = 2;i <= sqrt(r);i++) {
        for(ll j = max(i*i,(l+i-1)/i*i);j <= r;j+=i) {
            a[j-l] = 0;
        }
    }
    ll dem = 0;
    if(l == 1) a[0] = 0;
    for(int i = max(2ll,l);i <= r;i++) {
        if(a[i-l]) dem++;
    }
    cout << dem;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PRIME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> l >> r;
    sang();
    return 0;
}