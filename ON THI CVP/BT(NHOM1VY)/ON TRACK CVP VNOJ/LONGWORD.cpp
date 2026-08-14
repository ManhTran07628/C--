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
    getline(cin,s);
    int ans = 0,cnt = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] != ' ') cnt++;
        else {
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    ans = max(ans,cnt);
    cout << ans;
    return 0;
}