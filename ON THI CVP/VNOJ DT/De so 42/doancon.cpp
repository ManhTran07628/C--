#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];
ll n,m,k;

ll mod(string s)
{
    ll ans = 0;
    for(auto i:s) {
        ans = ans * 10 + (i-'0');
        ans = ans % k;
    }
    return ans;
}

ll binex(ll a,ll b)
{
    ll ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % k;
        a = a * a % k;
        b /= 2;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "doancon"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        a[i] = binex(mod(s),m);
    }
    b[0] = 1;
    ll sum = 0,ans = 0;
    for(int i = 1;i <= n;i++) {
        sum = (sum + a[i]) % k;
        ans += b[sum];
        b[sum]++;
    }
    cout << ans;
    return 0;
}