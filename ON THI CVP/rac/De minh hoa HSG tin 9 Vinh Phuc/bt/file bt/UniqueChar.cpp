#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "UniqueChar"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        for(auto c:s) {
            a[c]++;
        }
        ll ans = -1;
        for(int i = 0;i < s.size();i++) {
            if(a[s[i]] == 1) {
                ans = i+1;
                break;
            }
        }
        cout << ans << '\n';
        a.clear();
    }
    return 0;
}