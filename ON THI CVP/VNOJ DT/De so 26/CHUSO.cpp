#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CHUSO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    ll n,m;
    cin >> s >> n >> m;
    string s1 = s;
    reverse(s1.begin(),s1.end());
    s = s + s1;
    ll ns = s1.size() * pow(2,n);
    m--;
    if(ns < m) cout << -1;
    else cout << s[m%s.size()];
    return 0;
}