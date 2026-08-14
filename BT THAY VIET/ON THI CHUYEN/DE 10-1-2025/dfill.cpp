#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[10001][10001];
int n,m,k,ans = 0;

int mod = 1e6;
void backtrack(int id)
{
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] != a[i-1][j] && a[i][j] != a[i+1][j]
            && a[i][j] != a[i][j-1] && a[i][j] != a[i][j+1]
            && a[i][j] != 0
            ) {
                cnt++;
            }
        }
    }
    if(cnt == n*m) {
        ans = (ans+1)%mod;
        return;
    }
    for(int i = 1;i <= n;i++) {
        if(i == k) continue;
        for(int j = 1;j <= m;j++) {
            for(int h = id;h <= 3;h++) {
                
                if(h != a[i-1][j] && h != a[i+1][j]
                && h != a[i][j-1] && h != a[i][j+1]
                && a[i][j] == 0) {
                    a[i][j] = h;
                    backtrack(h);
                    a[i][j] = 0;
                }
                
            }
        }
    }
}

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
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        cin >> a[k][i];
    }
    if(n*m <= 20) {
        backtrack(1);
        cout << ans;
        return 0;
    }
    return 0;   
}