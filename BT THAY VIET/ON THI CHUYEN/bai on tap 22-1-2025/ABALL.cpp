#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    cin>> n >> k;
    int d = n-k*(k+1)/2;
    int q = d / k;
    int m = d % k;
    if(d < 0) {
        cout << -1;
        return 0;
    }
    if(m == 0) cout << k-1;
    else if(m > 0) cout << k;
    
    return 0;
}