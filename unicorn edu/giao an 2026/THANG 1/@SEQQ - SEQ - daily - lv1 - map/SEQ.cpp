#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n, k, a[N];
map<long long, long long> d;
int main()
{
    #define TASKNAME "seq"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" )) {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout); }
    cin >> n >> k;
    for (int i=1; i<=n; i++)
     cin >> a[i];
     bool kt = 0;
    for (int i=1; i<=n; i++){
        if (d[a[i]-k] ) {
                cout << i << " " << d[a[i]-k];
                kt = 1;
        return 0;
        }
        else if (d[a[i]+k] )
        {
            cout << d[a[i]+k] << " " << i;
            kt  = 1;
            return 0;
        }
        d[a[i]] = i;
    }
    if (!kt) cout << 0 << " " << 0;
    return 0;
}