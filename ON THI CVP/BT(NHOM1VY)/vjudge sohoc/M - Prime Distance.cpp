#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


void solve(ll L,ll R)
{
    ll p[R-L+1];
    for(ll i = L;i <= R;i++) p[i-L] = 1;
    for(ll i = 2;i*i <= R;i++) 
        for(ll j = max(i*i,(i+L-1)/i*i);j <= R;j+=i)
            p[j-L] = 0;
    if(1 >= L) {
        p[1-L] = 0;
    }
    vector<ll> v;
    for(ll i = L;i <= R;i++) {
        if(p[i-L]) v.push_back(i);
    }
    ll min1 = 1e9,max1 = 0;
    ll a1 = 0,b1 = 0,a2 = 0,b2 = 0,ok = 0;
    for(int i = 0;i < v.size()-1;i++) {
        if(abs(v[i]-v[i+1]) < min1) {
            a1 = v[i];b1 = v[i+1];
            min1 = abs(v[i]-v[i+1]);
            ok = 1;
        }
        if(abs(v[i]-v[i+1]) > max1) {
            a2 = v[i];b2 = v[i+1];
            max1 = abs(v[i]-v[i+1]);
            ok = 1;
        }
    }
    if(ok) cout<<a1<<","<<b1<<" are closest, "<<a2<<","<<b2<<" are most distant.";
    else cout<<"There are no adjacent primes.";
    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll L,U;
    while(cin >> L >> U) solve(L,U);
    return 0;
}