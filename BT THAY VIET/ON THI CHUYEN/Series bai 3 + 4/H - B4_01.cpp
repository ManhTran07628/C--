#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
char a[1001][1001];
int b[1001][1001];

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
        ll n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                cin >> a[i][j];
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = n;j >= 1;j--) {
                if(a[i][j] == '#') b[i][j] = 1;
                else b[i][j] = b[i][j+1];
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = n;j >= 1;j--) {
                if(a[j][i] != '#') ans += (b[j][i]==0);
                else break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}