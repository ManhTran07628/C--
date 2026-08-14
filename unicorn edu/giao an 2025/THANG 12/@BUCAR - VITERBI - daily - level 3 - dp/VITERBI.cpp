#include<bits/stdc++.h>
using namespace std;
const int N = 201;
long long m, n, t, o[N], a[N][N], b[N][N], f[N][N], tr[N][N];
void trace(int x, int k) {
    if (x==0) return;
    trace(x-1, tr[x][k]);
    cout << k << " ";

}
int main()
{

    #define TASKNAME "viterbi"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" )) {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout); }
    cin >> n >> m >> t;
    for (int i=1; i<=t; i++)
        cin >> o[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
         cin >> a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        cin >> b[i][j];
    for (int i=1; i<=n; i++){
     f[1][i] = b[i][o[1]];
    }
    for (int i=2; i<=t; i++)
        for (int j=1; j<=n; j++){
                f[i][j] = 1e9+7;
         for (int k=1; k<=n; k++)
          if (f[i][j] > f[i-1][k] + b[j][o[i]] + a[k][j]){
             f[i][j] = f[i-1][k] + b[j][o[i]] + a[k][j];
              tr[i][j] = k;
          }
    }
    long long m = 1e9+7, v = 0;
    for (int i=1; i<=n; i++)
        if (m > f[t][i]){
            m = f[t][i];
            v = i;
        }
    cout << m << '\n';
    trace(t, v);
    return 0;
}