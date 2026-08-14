#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n;
string s;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> s;
    int step = 0;
    for(int i = 1;i < n;i++) {
        if(s[i] == s[i-1] || (i - 2 >= 0 && s[i] == s[i-2])) {
            for(char j = 'a';j <= 'z';j++) {
                if(j == s[i-1]) continue;
                if(i - 2 >= 0 && j == s[i-2]) continue;
                if(i + 1 < n && j == s[i+1]) continue;
                if(i + 2 < n && j == s[i+2]) continue;
                s[i] = j;
                break;
            }
            step++;
        }
    }
    cout << step << '\n' << s;
    return 0;
}