#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 5e6+1;
int f[N][7],f1[N][7];
int n;
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
    cin >> n >> s;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j <= 5;j++) {
            f[i+1][j] = f[i][j];
        }
        f[i+1][s[i]-'A']++;
    }
    ll cnt = 0;
    for(int i = n-1;i >= 0;i--) {
        ll crr = 0;
        for(int j = 0;j <= 5;j++) {
            if(f[i+1][j] >= 1) crr++;
        }
        if(crr == 6) cnt++;
    }
    if(cnt == 0) cout << 0;
    else cout << cnt;
    return 0;
}