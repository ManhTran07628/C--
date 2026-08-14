#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+7;
ll a[N][N];
ll n,k,m;

ll hang(ll k,ll j)
{
    ll ans = 0;
    for(int i = 1;i <= j;i++) {
        ans += a[k][i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "bosoi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k >> m;
    for(int i = 1;i <= k;i++) {
        a[i][1] = i;
        a[i][2] = i;
        cout << i << " " << i << " ";
        for(int j = 3;j <= n;j++) {
            ll ans = hang(i,j);
            a[i][j] = ans + a[i-1][j];
            //cout << a[i][j] << " ";
            if(i == k && j == m) {
                cout << a[i][j];
                return 0;
            }
        }
        //cout << '\n';
    }
    return 0;
}