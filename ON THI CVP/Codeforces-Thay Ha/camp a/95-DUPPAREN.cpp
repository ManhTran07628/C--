#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    ll ans1 = 0,ans2 = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == s[i+1] && s[i] == '(') ans1++;
        if(s[i] == s[i+1] && s[i] == ')') ans2+=ans1;
        
    }
    cout << ans2;
    return 0;
}