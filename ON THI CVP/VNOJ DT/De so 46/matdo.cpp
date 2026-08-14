#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[200005][27];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "matdo"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 26;j++) {
            a[i][j] = a[i-1][j];
        }
        a[i][s[i-1]-'a']++;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 26;j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    ll cnt = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = )
    }
    return 0;
}