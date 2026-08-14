#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

multiset<pair<string,string>> lt;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(getline(cin,s)) {
        bool ok = 0;
        for(int i = 0;i < s.size();i++) {
            if(s[i] == '9' && s[i+1] == 'A') {
                ok = 1;
                break;
            }
        }
        if(ok) {
            int st = 0,d = 0,end = 0;
            for(int i = 0;i < s.size();i++) {
                if(s[i] == '#') d++;if(d == 1) {st = i;break;}
            }
            d = 0;
            for(int i = 0;i < s.size();i++) {
                if(s[i] == '#') d++;if(d == 2) {end = i;break;}
            }
            string name = "",fullid = "";
            for(int i = 0;i < end;i++) fullid += s[i];
            for(int i = end-1;i >= st+1;i--) {
                if(s[i] == ' ') break;
                name = s[i] + name;
            }
            lt.insert({name,fullid});
        }
    }
    for(auto i:lt) cout << i.se << '\n';
    return 0;
}