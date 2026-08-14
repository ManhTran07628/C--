#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
const int M = 5*1e2 + 5;
int m, n;
long long f[N][M], a[N];
int main()
{
    cin >> n >> m;
    for (int i=1 ; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (int i=1; i<=n; i++){
            int k = min(i,m);
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        f[i][k] = f[i-k][0] + a[i]-a[i-k];
        for (int x = 1; x<k; x++)
         f[i][x] = max(f[i-x][0] + a[i] - a[i-x], f[i-1][x+1]);
    }
    cout << f[n][0];
    return 0;
}