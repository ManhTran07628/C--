#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
ll a[N][N],b[N][N];

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
    
    ll n,m,q;
    cin >> n >> m >> q;
    while(q--) {
        ll x,y,u,v,k;
        cin >> x >> y >> u >> v >> k;
        a[x][y]+=k;
        a[x][v+1]-=k;
        a[u+1][y]-=k;
        a[u+1][v+1] += k;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            a[i][j] = a[i][j-1] + a[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            a[i][j] = a[i-1][j] + a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}