#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 1e9+7;
int d[7];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for(int i = 1;i <= n;i++) {
        if(s[i] == 'm') d[0]++;
        if(s[i] == 'r') d[2] = (d[2] + d[1]) % MOD;
        if(s[i] == 'i') d[3] = (d[3] + d[2]) % MOD;
        if(s[i] == 's') d[4] = (d[4] + d[3]) % MOD;
        if(s[i] == 'a') {
            d[1] = (d[1] + d[0]) % MOD;
            d[5] = (d[4] + d[5]) % MOD;
        }
    }
    cout << d[5];
    return 0;
}