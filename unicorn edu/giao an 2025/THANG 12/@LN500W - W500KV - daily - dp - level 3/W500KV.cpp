#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 0x3f3f3f3f;

int n, c, h[N], d[N][110];
int cal(int x, int y)
{
    return (x-y)*(x-y);
}
int main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if (fopen(TASKNAME".inp","r")){
        freopen(TASKNAME".inp", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    }
    cin >> n >> c;
    for (int i=0; i<n; i++)
        cin >> h[i];
    memset(d, 0x3f, sizeof(d));
    //cout << d[0] << endl;
    for (int i=h[0]; i<110; i++)
        d[0][i] = cal(i,h[0]);
    for (int i=1; i<n; i++)
        for (int j=h[i]; j<110; j++)
            for (int k=h[i-1]; k<110; k++)
                d[i][j] = min(d[i][j], d[i-1][k] + cal(j,h[i]) + c*abs(j-k));
    int ans = INF;
    for (int i=h[n-1]; i<110; i++)
        ans = min(ans, d[n-1][i]);
    cout << ans;
    return 0;
}