#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int ps[MAXN][26];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string t,s;
    char ch;
    cin >> t >> ch;
    int n = t.size();
    t = " " + t;
    for(int i = 1;i <= n;i++) {
        for(int j = 'a';j <= 'z';j++) {
            ps[i][j-'a'] += ps[i-1][j-'a'];
        }
        ps[i][t[i]-'a']++;
    }
    int ok = 0,pos = 0;
    for(int i = 1;i <= n;i++) {
        int flag = 1;
        for(int j = 'a';j <= 'z';j++) {
            int left = ps[i][j-'a'];
            int right = ps[n][j-'a']-ps[i][j-'a'];
            char d = char(j);
            if(left != right && d != ch) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            pos = i;
            ok = 1;
        }
    }
    if(!ok) {
        cout << -1;
        return 0;
    }
    for(int i = 1;i <= pos;i++) cout << t[i];
    return 0;
}
