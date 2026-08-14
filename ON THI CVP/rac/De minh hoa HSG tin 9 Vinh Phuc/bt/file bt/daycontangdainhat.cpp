#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+7;
ll a[N],b[N][N];

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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            if(a[j] > a[i]) {
                b[i][j] = max(b[i][j],b[i][j]+1);
            }
        }
    }
    cou << b[n][n];
    return 0;
}