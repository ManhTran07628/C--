#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int p[256],c[256];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0;i < n;i++) {
        p[s[i]]++;
    }
    ll ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 'a';j <= 'z';j++) 
            ans += c[j]*(p[j]-c[j]-(s[i] == j));
        c[s[i]]++;
    }
    cout << ans;
    // for(int i = 1;i <= n;i++) {
    //     for(char j = 'a';j <= 'z';j++) {
    //         if(p[i][j] != 0) cout << j << ' ' << p[i][j] << '\n';
    //     }
    //     cout << '\n';
    // }
    return 0;
}