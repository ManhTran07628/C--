#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1;i <= n;i++) {
        for(int j = 'a';j <= 'z';j++) {
            a[i][j-'a'] = a[i-1][j-'a']; 
        }
        a[i][s[i-1]-'a']++;
    }
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        int ok = 0;
        for(int i = 'a';i <= 'z';i++) {
            if((a[r][i-'a']-a[l-1][i-'a']) % 2 == 1) ok++;
        }
        if(ok > 1) cout << "NO";
        else cout << "YES" << '\n';
    }
    return 0;   
}