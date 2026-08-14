#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 200 + 7;
int num_row,num_col;//,cut_row[MM][MM],cul_col[MM][MM];
char a[MM][MM];

bool cut_row(int i,int j)
{
    for(int k = 1;k <= num_col;k++) {
        if(a[i][k] != a[j][k]) return 1;
    }
    return 0;
}

bool cut_col(int i,int j)
{
    for(int k = 1;k <= num_row;k++) {
        if(a[k][i] != a[k][j]) return 1;
    }
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> num_row >> num_col;
    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) 
            cin >> a[i][j];

    int res = 0;
    for(int i = 1;i < num_row;i++) {    
        res += cut_row(i,i+1);
    }
    for(int i = 1;i < num_col;i++) {    
        res += cut_col(i,i+1);
    }
    cout << res;
    return 0;
}