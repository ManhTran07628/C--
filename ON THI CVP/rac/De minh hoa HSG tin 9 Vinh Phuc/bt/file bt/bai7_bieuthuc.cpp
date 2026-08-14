#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<char> a;
int main()
{
    freopen("bieuthuc.inp","r",stdin);
    freopen("bieuthuc.out","w",stdout);
    string s;
    cin >> s;
    ll dem = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*') {
            ll vtd = i;
            string k;
            ll tmp = (s[i - 1] - '0');
            while(i < s.size() && s[i] == '*') {
                tmp *= (s[i + 1] - '0');
                i += 2;
            }
            while(tmp > 0) {
                ll ans = tmp % 10;
                char c = ans + '0';
                k += c;
                tmp /= 10;
            }
            reverse(k.begin(), k.end());
            s = s.substr(0, vtd - 1) + k + s.substr(vtd + 2);
            i = vtd - 1;
        }
    }
    ll tmp = 0;
    ll kq = (s[0]-'0');
    for(int i = 1;i < s.size();i++) {
        if(s[i] == '+') {
            while(isdigit(s[i+1]) && i < s.size()) {
                tmp = tmp * 10 + (s[i+1] - '0');
                i++;
            }
            kq += tmp;
            tmp = 0;
        }
        else if(s[i] == '-') {
            while(isdigit(s[i+1]) && i < s.size()) {
                tmp = tmp * 10 + (s[i+1] - '0');
                i++;
            }
            kq -= tmp;
            tmp = 0;
        }
    }
    cout << kq;
    return 0;
}
