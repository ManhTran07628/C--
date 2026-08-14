#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "XINCHAO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    string k;
    cin >> k;
    while(t--) {
        string s;
        cin >> s;
        ll j = 0,check = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == k[j]) j++;
            if(j == k.size()-1) {
                check = 1;
                break;
            }
        }
        if(check) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}