#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
        ll n;
        cin >> n;
        ll slso = 0;
        string k;
        cin >> k;
        string k1 = k.substr(0,4);
        string k2 = k.substr(n-4);
        string k3 = k.substr(0,3)+k.substr(n-1);
        string k4 = k.substr(0,2)+k.substr(n-2);
        string k5 = k.substr(0,1)+k.substr(n-3);
        string tmp = "2020";
        if(k1==tmp||k2==tmp||k3==tmp||k4==tmp||k5==tmp) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}