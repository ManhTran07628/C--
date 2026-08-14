#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

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
    string s,p;
    getline(cin,s);
    cin >> p;
    ll cnt = 0;
    for(int i = 0;i < s.size();i++) {
        string chk;
        if(s[i] == ' ' || i == 0) {
            ll m = 1;
            if(i == 0) m = 0;
            for(int j = i+m;j < s.size();j++) {
                if(s[j] == ' ') break;
                chk += s[j];
            }
            if(chk.size() == p.size()) {
                for(int j = 0;j < p.size();j++) {
                    if(p[j] == '?') chk[j] = '?';
                }
                if(chk == p) cnt++;
                //cout << chk << " " << '\n';
            }
        }
    }
    cout << cnt;
    return 0;
}