#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n, a[N], b[N], x[N], y[N];
int main()
{
     #define TASKNAME "rtriang2"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
        }
    cin >> n;
    for (int i=1; i<=n; i++){
         cin >> a[i] >> b[i];
         x[a[i]]++;
         y[b[i]]++;
    }
    long long ans = 0;
    for (int i=1; i<=n; i++)
        ans += (x[a[i]]-1)*(y[b[i]] -1);
    cout << ans;
    return 0;
}