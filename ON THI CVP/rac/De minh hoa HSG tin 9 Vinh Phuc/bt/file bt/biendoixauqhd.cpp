#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],f[1001][1001];
string s,t;

void ans()
{
    for(int i = 0;i < s.size();i++) {
        for(int j = 0;j < t.size();j++) {
            if(s[i] == t[j]) f[i][j] = f[i][j-1];
            else {
                f[i][j] = min({f[i-1][j]+1,f[i][j-1]+1,f[i-1][j-1]+1});
            }
        }
    }
    cout << f[s.size()-1][t.size()-1] << '\n';
}

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
    ll t;
    cin >> t;
    while(t--) {
        cin >> s >> t;
        ans();
    }
    return 0;
}