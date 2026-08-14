#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "EbneNum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string s,k;
        cin >> s;
        ll kt = -1;
        ll i = 0;
        while(i < n) {
            ll sum = 0;
            k += s[i];
            for(int j = 0;j <= i;j++) {
                sum += s[j]-'0';
            }
            if(sum % 2 == 0 && (s[i]-'0') % 2 != 0) {
                kt = 1;
                break;
            }
            i++;
        }
        if(kt == 1) {
            cout << k << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}