#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
string s;
ll check(ll l,ll r)
{
    if(r-l+1 < 1) return 0;
    while(l <= r) {
        if(s[l] != s[r]) return 0;
        l++;r--;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "XAUDX"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> s;
    ll cnt = 1;
    for(int i = 0;i < s.size();i++) {
        for(int j = i;j < s.size();j++) {
            ll c = j - i+1;
            if(check(i,j)) cnt = max(cnt,c);
        }
    }
    cout << cnt;
    return 0;
}