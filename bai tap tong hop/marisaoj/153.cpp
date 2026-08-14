#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int f[2001][2001];
char a[2001];
string s;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> s;
    for(int i = 1;i <= s.size();i++) {
        a[i] = s[i-1];
        f[i][i] = 1;
        if(s[i-1] == s[i]) f[i][i+1] = 1;
    }
    int n = s.size();
    for(int i = 1;i <= n;i++) {
        for(int j = )
    }

    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        if(f[l][r]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}