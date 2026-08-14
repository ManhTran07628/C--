#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll x[40001],y[40001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int w,h,n;
    cin >> w >> h >> n;
    for(int i = 1;i <= n;i++) {
        cin >> x[i] >> y[i];
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    ll ans = 0;
    x[n+1] = w+1;
    y[n+1] = h+1;
    ll row = 0;
    ll col = 0;
    for(int i = 0;i <= n;i++) {
        row = max(row,x[i+1]-x[i]-1);
        col = max(col,y[i+1]-y[i]-1);
    }
    cout << row*col;
    return 0;
}