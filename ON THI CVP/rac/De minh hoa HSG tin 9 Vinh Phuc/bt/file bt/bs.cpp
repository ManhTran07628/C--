#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+7;
ll a[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "bs"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll c = 1;
    for(int i = 1;i <= n/2;i++) {
        for(int j = 1;j <= n;j++) {
            a[i][j] = n*(c-1)+j;
        }
        c++;
        for(int j = 1;j <= n;j++) {
            a[n-i+1][j] = n*c-j+1;
        }
        c++;
    }
    if(n % 2 == 1) {
        for(int i = 1;i <= n;i++) {
            a[(n+1)/2][i] = n*(c-1)+i;
        }
    }


    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}