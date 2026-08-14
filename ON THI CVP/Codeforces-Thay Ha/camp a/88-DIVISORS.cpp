#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> f;
    for(int i = 1;i <= sqrt(n);i++)
    {
        if(n%i == 0) {
            f.push_back(i);
            if(n / i != i) f.push_back(n/i);
        }
    }
    sort(f.begin(),f.end());
    for(ll i :f) cout << i << ' ';
    return 0;
}