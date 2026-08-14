#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ErasingZeroes"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll dem = 0;
        for(int i = 1;i < s.size();i++) {
            if(s[i] == '0' && s[i-1] == '1') f.push_back(i);
            if(s[i] == '0' && s[i+1] == '1' && i+1 < s.size()) f.push_back(i);
        }
        for(int i = 0;i < f.size();i++) {
            dem += (f[i+1]+1)-f[i];
        }
        cout << dem << '\n';
        f.clear();
    }
    return 0;
}