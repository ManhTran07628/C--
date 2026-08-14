#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,vector<ll>> f;
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
        ll a1;
        cin >> a1;
        f[a1].push_back(i);
    }
    while(q--) {
        ll x,k;
        cin >> x >> k;
        cout << f[x][k-1] << '\n';
    }
    return 0;
}