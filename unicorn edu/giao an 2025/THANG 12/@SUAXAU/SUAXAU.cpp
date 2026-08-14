#include<bits/stdc++.h>
using namespace std;
int n,m,a,b, ins['~'], del['~'];
string s;
char c;
long long ans[3000][3000];
int main()
{
    cin >> n >> m;
    cin >> s;
    for (int i=1; i<=n; i++)
    {
        cin >> c >> a >> b;
        ins[c] = a;
        del[c] = b;
    }
    for (int l=m-1; l>=0; l--)
    for (int r=l; r<m; r++)
        {
        ans[l][r] = min(ins[s[r]],del[s[r]]) + ans[l][r-1] ;
        ans[l][r] = min(ans[l][r], min(ins[s[l]],del[s[l]]) + ans[l+1][r]) ;
        if (s[l] == s[r]) ans[l][r] = ans[l+1][r-1];

    }
    cout << ans[0][m-1];
    return 0;
}