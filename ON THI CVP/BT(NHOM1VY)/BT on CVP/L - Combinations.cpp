#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll c[101][101];
ll C(ll n, ll k){
   if(n == k || k == 0)return 1;
   if(c[n][k]) return c[n][k];
   c[n][k] = C(n-1,k-1) + C(n-1,k);
   return c[n][k];
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
    for(int i = 0;i <= 100;i++) {
        for(int j = 0;j <= i;j++) {
            c[i][j] = C(i,j);
        }
    }
    ll n,m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) return 0;
        cout << n << " things taken " << m <<" at a time is " << c[n][m] << " exactly." << '\n';
    }
    return 0;
}