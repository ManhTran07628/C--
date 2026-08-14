#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;

bool check(string s,string t)
{
    for(int i = 0,j = 0;i < s.size();i++) {
        if(s[i] == t[j]) j++;
        if(j == t.size()) return 1;
    }
    return 0;
}

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
    string s,t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0;i < s.size();i++) {
        for(int j = i;j < s.size();j++) {
            string a = s;
            a.erase(i,j-i+1);
            if(check(a,t)) ans = max(ans,j-i+1);
        }
    }
    cout << ans;
    return 0;
}