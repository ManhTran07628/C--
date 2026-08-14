#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "BAI1"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,m,k;
    cin >> n >> m >> k;
    int ans = 1e9;
    if(n >= k) ans = n * k * 0.8;
    else 
    {
        ans = (n*m*0.8);
        ans = min(ans,m*k);
    }
    cout << ans; 
    return 0;
}