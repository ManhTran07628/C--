#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];

ll tongcs(ll k)
{
    ll ans = 0;
    while(k > 0) {
        ans += k % 10;
        k /= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "bpairs"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[tongcs(a[i])]++;
    }
    ll ans = 0;
    for(auto i:b) {
        ans += (i-1)*i/2;
    }
    cout << ans;
    return 0;
}