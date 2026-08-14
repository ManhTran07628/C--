#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];


ll recs(ll x,ll n)
{
    if(n == 0) return 1;
    ll ans = recs(x,n/2);
    if(n % 2 == 0) return ans * ans;
    else return ans * x * ans; 
}

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
    ll x,n;
    cin >> x >> n;
    cout << recs(x+1,n);
    return 0;
}