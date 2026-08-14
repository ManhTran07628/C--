#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
map<ll,ll> a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "LCS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s1,s2;
    cin >> s1 >> s2;
    for(auto c:s1) a[c] = 1;
    for(auto c:s2) b[c] = 1;
    ll ans = 0;
    for(auto c:s1) {
        if(b[c] == 0) ans++;
    }
    for(auto c:s2) {
        if(a[c] == 0) ans++;
    }
    cout << ans;
    return 0;
}