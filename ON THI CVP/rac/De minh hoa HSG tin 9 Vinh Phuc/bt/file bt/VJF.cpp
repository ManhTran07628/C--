#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
char a[101][101];


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
        ll n,m;
        cin >> n >> m;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                cin >> a[i][j];
            }
        }
        ll so = 0;
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= n;j++) {
                if(a[j][i] == 'v' && so == 0) {
                    so++;
                    break;
                }
                if(a[j][i] == 'i' && so == 1) {
                    so++;
                    break;
                }
                if(a[j][i] == 'k' && so == 2) {
                    so++;
                    break;
                }
                if(a[j][i] == 'a' && so == 3) {
                    so++;
                    break;
                }
            }
        }
        if(so == 4) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}