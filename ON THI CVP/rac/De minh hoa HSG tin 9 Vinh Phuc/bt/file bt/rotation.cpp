#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "rotation"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    ll n = s.size();
    s += s;
    for(int i = 0;i < n;i++) {
        string tmp;
        for(int j = i;j < i+n;j++) {
            tmp += s[j];
        }
        cout << tmp << '\n';
    }
    return 0;
}