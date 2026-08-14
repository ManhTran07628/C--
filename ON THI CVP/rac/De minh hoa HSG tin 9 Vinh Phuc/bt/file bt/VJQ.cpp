#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        ll so0 = 0,so1 = 0,kq = -1;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == '0') {
                while(s[i] == '0' && i < s.size()) i++;
                so0++;
                i--;
            }
            if(s[i] == '1') {
                while(s[i] == '1' && i < s.size()) i++;
                so1++;
                i--;
            }
        }
        if(so0 == 1) kq = 1;
        if(so0 >= 2) kq = 2;
        if(so0 == 0) kq = 0;
        cout << kq << '\n';
    }
    return 0;
}