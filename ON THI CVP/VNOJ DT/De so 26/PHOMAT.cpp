#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll f[1001][1001],t[N],w[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PHOMAT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,l;
    cin >> n >> l;
    for(int i = 1;i <= n;i++) {
        cin >> t[i] >> w[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= l;j++) {
            f[i][j] = f[i-1][j];
            if(j >= t[i]) {
                f[i][j] = max(f[i][j],f[i-1][j-t[i]] + w[i]);
            }
            //cout << f[i][j] << " ";
        }
        //cout << '\n';
    }
    cout << f[n][l];
    return 0;
}