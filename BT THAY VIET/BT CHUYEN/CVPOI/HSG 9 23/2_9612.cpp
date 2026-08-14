#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;


bool check1(string s)
{
    if(s.size() == 1) return 0;
    for(int i = 0;i < s.size() - 1;i++) {
        if(s[i] == '*' && s[i+1] == '*') return 1;
    }
    return 0;
}

bool check2(string s)
{
    int l = -1,r = MM;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '>') {
            l = i;
            break;
        }
    }
    for(int i = s.size() - 1;i >= 0;i--) {
        if(s[i] == '<') {
            r = i;
            break;
        }
    }
    if(l >= 0 && r <= s.size() - 1 && l < r) return 1;
    return 0;
}

bool check3(string s)
{
    for(int i = 0;i < s.size() - 1;i++) {
        if(s[i] == '*' && s[i+1] == '<') return 1;
        if(s[i] == '>' && s[i+1] == '*') return 1;
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if(s.size() == 1) {
            cout << 1 << '\n';
            continue;
        }
        if(check1(s) || check2(s) || check3(s)) cout << -1 << '\n';
        else {
            int res1 = 0, res2 = 0, res3 = 0;
            for(int i = 0;i < s.size();i++) {
                if(s[i] == '<') res1++;
                if(s[i] == '>') res2++;
                if(s[i] == '*') res3++;
            }
            cout << max(res1 + res3,res2 + res3) << '\n';
        }
    }
    return 0;
}