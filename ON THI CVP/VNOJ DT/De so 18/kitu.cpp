#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "kitu"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    ll cnt = 0;
    for(int i = 0;i < s.size();i++) {
        if(isdigit(s[i])) cnt++;
    }
    cout << cnt;
    return 0;
}