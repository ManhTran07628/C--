#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

string chuyen(ll n)
{
    string t = "";
    while(n > 0) {
        char tmp = char((n % 10) +'0');
        t = t + tmp;
        n /= 10;
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    int mindigit = 10;
    string s = chuyen(n);
    reverse(s.begin(),s.end());
    for(auto i:s) mindigit = min(mindigit,i-'0');
    if(mindigit == 9) cout << n + 2;
    else {
        if(n % 10 == 0) {
            n++;
            string t = chuyen(n);
            cout << t;
            reverse(t.begin(),t.end());
            return 0;
        }
        ll ans = pow(10,s.size()-1);
        string t = chuyen(ans);
        ll pos = 0,val = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] - '0' < 9) {
                pos = i,val = s[i]-'0';
                break;
            }
        }
        for(int i = 0;i < pos;i++) {
            t[i] = '9';
        }
        t[pos] = '0' + val + 1;
        reverse(t.begin(),t.end());
        cout << t;
    }
    return 0;
}