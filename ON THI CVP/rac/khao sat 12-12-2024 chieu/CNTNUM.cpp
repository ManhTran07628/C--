#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[101][1001];
ll MOD = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "cntnum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s;
    cin >> n >> s;
    for(int i = 1;i <= 9;i++) {
        f[1][i] = 1;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= s;j++) {
            for(int nums = 0;nums <= 9;nums++) {
                if(nums == 0 && i == 1) continue;
                if(j >= nums) {
                    f[i][j] = (f[i][j] + f[i-1][j-nums]) % MOD;
                }
            }
            //cout << f[i][j] << " ";
        }
        //cout << '\n';
    }
    cout << f[n][s];
    return 0;
}