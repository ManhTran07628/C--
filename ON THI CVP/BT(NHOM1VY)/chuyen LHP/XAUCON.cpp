#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll p[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    if((s[0]-'0') % 4 == 0) ans++;
    if((s[1]-'0') % 4 == 0) ans++;
    if(((s[0]-'0')*10 + s[1]-'0')%4==0)ans++;
    for(int i = 2;i < n;i++) {
        if((s[i]-'0')%4==0)ans++;
        if(((s[i-1]-'0')*10+s[i]-'0') % 4 == 0) ans += i;
    }
    cout << ans;
    return 0;
}