#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);
    int ans = 0;
    if(s[0] != ' ') ans++;
    for(int i = 0;i < s.size()-1;i++) {
        if(s[i] == ' ' && s[i+1] != ' ') ans++;
    }
    cout << ans;
    return 0;
}