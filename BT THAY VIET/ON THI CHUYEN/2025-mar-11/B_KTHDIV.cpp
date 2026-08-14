#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for(ll i = 1;i * i <= n;i++) {
        if(n % i == 0) {
            v.push_back(i);
            if(n / i != i) v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    if(v.size() < k) {
        cout << -1;
        return 0;
    }
    cout << v[k-1];
    return 0;
}