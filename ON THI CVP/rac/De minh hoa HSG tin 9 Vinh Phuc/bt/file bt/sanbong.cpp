#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3;

struct tmp
{
    ll a,b,c;
};

tmp s[N];


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
    for(int i = 1;i <= n;i++) {
        cin >> s[i].a >> s[i].b >> s[i].c;
    }
    sort(s+1,s+n+1);
    for(int i = 1;i <= n;i++) 
        cout << s[i].a << " " << s[i].b << " " << s[i].c << '\n';
    return 0;
}