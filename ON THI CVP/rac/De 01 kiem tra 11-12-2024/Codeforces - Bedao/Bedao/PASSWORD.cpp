#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 8e6+7;
ll a[N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PASSWORD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1;i <= N;i++) {
        string tmp = to_string(i);
        s += tmp;
    }
    cout << s[n-1] << s[n] << s[n+1] << s[n+2];
    return 0;
}