#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a1;
void tsnt(ll k)
{
    ll dem = 1;
    for(int i = 2;i <= sqrt(k);i++) {
        while(k % i == 0) {
            a1[i]++;
            k /= i;
        }
    }
    if(k > 1) a1[k]++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "uocso"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        tsnt(a);
        tsnt(b);
        ll dem = 1;
        for(auto c:a1) {
            dem *= (c.second+1);
        }
        cout << dem << '\n';
        a1.clear();
    }
    return 0;
}
