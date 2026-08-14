#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
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
    string n;
    cin >> n;
    string k;
    if(n[0] == '-') k = n.substr(1);
    else k = n.substr(0);
    reverse(k.begin(),k.end());
    if(n[0] == '-') k = '-' + k;
    ll ans = stoll(k);
    cout << ans;
    return 0;
}