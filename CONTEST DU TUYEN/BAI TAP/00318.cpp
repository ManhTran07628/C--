#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,k;
int a[MM],b[MM],c[MM];
int f1[MM][2],f2[MM][2];
ll dp1[MM][2],dp2[MM][2];
// dp1: max loi nguyen (0/1) -> bth/honloan
// dp2: max phap su (0/1) -> bth/honloan

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i] >> c[i];
        dp1[i][0] = dp1[i-1][0];
        dp1[i][1] = dp1[i-1][1];
        dp2[i][0] = dp2[i-1][0];
        dp2[i][1] = dp2[i-1][1];
        f1[i][0] = f1[i-1][0];
        f1[i][1] = f1[i-1][1];
        f2[i][0] = f2[i-1][0];
        f2[i][1] = f2[i-1][1];
        
        if(a[i] <= 0) {
            // hon loan
            if(b[i] < 0) {
                
            }
        }




    }
    return 0;
}