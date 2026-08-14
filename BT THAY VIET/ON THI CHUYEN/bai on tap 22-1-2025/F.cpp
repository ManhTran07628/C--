#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int dp[5001][5001][2];
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
    int n,k;
    cin >> n >> k;
    dp[k][1][0] = 1;
    dp[k][1][1] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(j != )
        }
    }
    return 0;
}