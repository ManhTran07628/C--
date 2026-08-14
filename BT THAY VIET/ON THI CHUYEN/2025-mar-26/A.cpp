#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 5e4+7;
int p[MAXN][26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i = 1;i <= s.size();i++) {
        for(int j = 0;j < 26;j++) {
            p[i][j] = p[i-1][j];
        }
        p[i][s[i-1]-'a']++;
    }
    int q;
    cin >> q;
    while(q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        bool ok = 1;
        for(int i = 0;i < 26;i++) {
            int f1 = p[b][i] - p[a-1][i];
            int f2 = p[d][i] - p[c-1][i];
            if(f1 != f2) ok = 0;
        }
        if(ok) cout << "DA";
        else cout << "NE";
        cout << '\n';
    }
    return 0;
}