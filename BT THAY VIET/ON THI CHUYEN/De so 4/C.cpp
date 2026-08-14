#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<char> f{'8','0','2','4','6'};

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
    string s;
    cin >> n;
    while(n > 1) {
        s += f[n%5];
        n = (n+4)/5;
    }
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}