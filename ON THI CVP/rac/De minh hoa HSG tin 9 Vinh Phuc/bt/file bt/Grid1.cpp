#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
char a[1001][1001];
ll f[1001][1001];
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
    ll h,w;
    cin >> h >> w;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            cin >> a[i][j];
        }
    }
    ll tmp =1e9+7;
    f[1][1] = 1;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            if(i == 1 && j == 1) {
                //cout << f[i][j] << " ";
                continue;
            }
            if(a[i][j] == '.')
                f[i][j] = (f[i-1][j] + f[i][j-1]) % tmp;
            else {
                f[i][j] = 0;
            }
            //cout << f[i][j] << " ";
        }
        //cout << '\n';
    }
    cout << f[h][w];
    return 0;
}