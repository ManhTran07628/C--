#include<bits/stdc++.h>
using namespace std;
const int N = 5*1e6+10;
struct item{
   int x, y;
};
item a[N];
bool kt[N];
long long ans[N];
bool cmp(item u, item v)
{
    return u.x < v.x;
}
int n;
int main()
{
     #define TASKNAME "segsum"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
        }
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].x >> a[i].y;
        int d = INT_MAX, c = 0;
    for (int i=1; i<=n; i++){
            if (a[i].x < a[i].y){
              ans[a[i].y]--;
              ans[a[i].x]++;
            }
            else
                kt[a[i].x] = 1;
            d = min(d, a[i].x);
            c = max(c, a[i].y);
    }
    //cout << endl << endl;
   // cout << d << " " << c << endl;
    for (int i=d; i <= c+1; i++){
            ans[i] += ans[i-1];
           //cout << i << " " << ans[i] << endl;
        if (ans[i] == 0 && ans[i-1]> 0 ) cout << i << "\n";
        else
        if (ans[i-1] == 0 && ans[i] > 0) cout << i << " ";
        else
            if (ans[i] == 0 && ans[i-1] == 0 && kt[i]) cout << i << " " << i << "\n";
    }
     return 0;
}