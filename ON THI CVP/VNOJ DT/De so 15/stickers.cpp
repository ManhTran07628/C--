#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
map<ll,ll> a,b;
set<ll> f;
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
    string s,t;
    cin >> s >> t;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '2' || s[i] == '5') {
            a[2]++;
            a[5]++;
        }
        if(s[i] == '6' || s[i] == '9') {
            a[6]++;
            a[9]++;
        }
    }
    for(int i = 0;i < t.size();i++) {
        if(t[i] == '2' || t[i] == '5') {
            b[2]++;
            b[5]++;
        }
        if(t[i] == '6' || t[i] == '9') {
            b[6]++;
            b[9]++;
        }
    }
    ll ans = 1e9;
    for(int i = 0;i <= 9;i++) {
        if(b[i] != 0) {
            if(i == 2)
            ans = min(ans,a[i]/b[i]);
        }
        cout << i << " ";
    }
    cout << ans;
    return 0;
}