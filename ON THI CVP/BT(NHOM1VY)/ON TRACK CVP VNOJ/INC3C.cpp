#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int p[27],t[27];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll ans = 0;
    int n = s.size();
    for(int i = 1;i <= n;i++) {
        p[s[i-1]-'a']++;
    }
    for(int i = 1;i <= n;i++) {
        int p1 = 0,q = 0;
        for(int j = 0;j < s[i-1]-'a';j++) 
        {
            p1 += t[j];
        }
        for(int j = s[i-1]-'a'+1;j < 26;j++) 
        {
            q += (p[j]-t[j]);
        }
        ans += p1*q;
        t[s[i-1]-'a']++;
    }
    cout << ans;
    return 0;
}
