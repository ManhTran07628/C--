#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

ll ktra(string k)
{
    for(int i = 0;i < k.size();i++) {
        a[k[i]]++;
    }
    if(a['0'] == a['1']) return 0;
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "goodstring"
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
        ll n = s.size();
        ll kq = n;
        for(ll i = 1;i <= n;i++) {
            ll j = 0,kt = 1;
            string k;
            while(j < n) {
                k += s[j];
                if((j+1) % i == 0) {
                    if(ktra(k) == 0) {
                        kt = 0;
                        break;
                    }
                }
                j++;
            }
            if(kt == 1) {
                kq = min(kq,i);
            }
        }
        cout << kq << '\n';
    }
    return 0;
}