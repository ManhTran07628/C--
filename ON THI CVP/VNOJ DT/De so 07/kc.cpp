#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "kc"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 0;i < s.size();i++) {
        if(isdigit(s[i])) {
            ll sum = 0;
            while(isdigit(s[i]) && i < s.size()) {
                sum = sum * 10 + (s[i]-'0');
                i++;
            }
            ans += sum;
        }
    }
    cout << ans;
    return 0;   
}