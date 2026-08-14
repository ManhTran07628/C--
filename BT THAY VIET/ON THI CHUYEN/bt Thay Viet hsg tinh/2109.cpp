#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
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
    ll q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        ll cnt = 100000;
        ll n = s.size();
        for(int i = 0;i < n-2;i++) {
            if(s[i+1] != 'M') {
                cnt = min(cnt,(ll)((n-3)+(s[i]!='M')+(s[i+2]!='O')));
            }
        }
        if(cnt == 100000) cout << -1 << '\n';
        else cout << cnt << '\n';
    }
    return 0;
}