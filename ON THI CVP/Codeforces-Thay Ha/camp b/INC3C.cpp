#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll t[26],l[26];

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
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++) {
        t[s[i]-'a']++;
    }
    ll ans = 0;
    for(int i = 0;i < s.size();i++) {
        ll p = 0,q = 0;
        for(int j = 0;j + 'a' < s[i];j++) {
            p += l[j];
        }
        for(int j = s[i]-'a'+1;j < 26;j++) {
            q += t[j] - l[j]; 
        }
        ans += p * q;
        l[s[i]-'a']++;
    }
    cout << ans;
    return 0;   
}