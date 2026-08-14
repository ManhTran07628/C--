#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
ll f[N][N];

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
    ll n,m;
    cin >> n >> m;
    string x,y;
    cin >> x >> y;
    ll max1 = 0;
    for(int i = 0;i < x.size();i++) {
        for(int j = 0;j < y.size();j++) {
            if(x[i] == y[j]) {
                f[i+1][j+1] = f[i][j]+1;
            }
            else {
                f[i+1][j+1] = max(f[i][j+1],f[i+1][j]);
            }
            max1 = max(max1,f[i+1][j+1]);
        }
    }
    cout << max1;
    return 0;
}
