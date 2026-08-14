#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

ll check(ll k)
{
    ll x = int(sqrt(k));
    if(x*x == k) return 1;
    else return 0;
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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        string s;
        cin >> n >> s;
        ll sls1 = 0,sls0 = 0;
        for(int i = 0;i < n;i++) {
            if(s[i]=='1')sls1++;
            else sls0++;
        }
        if(sls0 == 0 && n > 4) {
            cout << "No" << '\n';
            continue;
        }
        if(check(sls1) && check(sls0)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}