#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],b[N],f[N][3][3];

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
        cin >> b[i];
    }
    f[1][0][1] = a[i]; // A
    f[1][1][1] = b[i]  // P
    for(int i = 1;i <= n;i++) {
        f[i][0][2] = max(f[i][0][2],f[i][0][1] + a[i]);
        f[i][0][1] = max(f[i][0][1],max(f[i-1][0][1],f[i-1][1][2] + a[i]));
        f[i][1][2] = max() 
    } 

    return 0;
}