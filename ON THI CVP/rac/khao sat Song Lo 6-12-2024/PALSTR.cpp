#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

ll check(string a)
{
    ll m = a.size();
    for(int i = 0;i < a.size();i++) {
        if(a[i] != a[m-i-1]) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PALSTR"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s,f;
    cin >> s;
    ll cnt = 0;
    ll n = s.size();
    f = s;
    if(check(s)) {
        cout << 0;
        return 0;
    }
    for(int i = n-2;i >= 0;i--) {
        string k = f + s[i];
        if(check(k)) {
            cout << cnt+1;
            return 0;
        }
        cnt++;
        f += s[i];
    }
    return 0;
}