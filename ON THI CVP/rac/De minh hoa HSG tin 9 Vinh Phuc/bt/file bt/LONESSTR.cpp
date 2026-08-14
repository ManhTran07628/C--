#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
map<ll,ll> a;
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll dem = 0,tong = 0;
    a[0] = 1;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '0') tong--  ;
        else tong++;
        dem += a[tong];
        a[tong]++;
    }
    cout << dem;
    return 0;
}