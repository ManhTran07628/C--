#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
map<ll,ll> b;

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
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,a;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a;
            b[a]++;
        }
    }
    ll maxn = 0;
    for(auto i:b) {
        maxn = max(maxn,i.second);
    }
    for(auto i:b) {
        if(i.se == maxn) cout << i.fi << ' ';
    }
    return 0;
}