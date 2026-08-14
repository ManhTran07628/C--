#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
char a[51][51];
int n,m; 
int dem(char c,int x,int y) // x != y
{
    int d = 0;
    for(int i = x;i <= y;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] != c) d++;
        }
    }
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    int ans = 10000;
    for(int i = 1;i <= n-2;i++) {
        for(int j = i+1;j <= n-1;j++) {
            int d1 = dem('W',1,i);
            int d2 = dem('B',i+1,j);
            int d3 = dem('R',j+1,n);
            ans = min(ans,d1+d2+d3);
        }
    }
    cout << ans;
    return 0;
}