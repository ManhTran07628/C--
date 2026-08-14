#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 5e6+1;
int a[N][27];
string s;
ll t,l,r;

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
    cin >> t >> s;
    for(int i = 0;i < s.size();i++) {
        for(int j = 0;j < 26;j++) {
            a[i+1][j] = a[i][j];
        }
        a[i+1][s[i]-'a']++;
    }
    while(t--)
    {
        cin >> l >> r;
        ll cnt = 0;
        for(int i = 0;i < 26;i++) {
            if((a[r][i] - a[l-1][i]) % 2 != 0) cnt++;
        }
        if(cnt == 0 || cnt == 1) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}
