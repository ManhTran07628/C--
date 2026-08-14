#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MinMum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        string s,k1;
        cin >> s;
        if(s.size() == 1) {
            if(k > 0) {
                cout << 0 << '\n';
                continue;
            }
        }
        for(int i = 0;i < s.size();i++) {
            ll so = -1;
            if(k > 0) {
                if(i == 0) {
                    if(s[i] != '1') {
                        k--;
                        so = 1;
                    }
                }
                else {
                    if(s[i] != '0') {
                        k--;
                        so = 0;
                    }
                }
            }
            if(so == -1) k1 += s[i];
            else if (so == 1) k1+='1';
            else if(so == 0) k1+='0';
        }
        cout << k1 << '\n';
    }
    return 0;
}