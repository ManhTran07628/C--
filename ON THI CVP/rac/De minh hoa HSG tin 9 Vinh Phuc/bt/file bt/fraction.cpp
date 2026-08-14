#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "fraction"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll b,n;
    cin >> b >> n;
    ll kq = 0;
    for(int m = 1;m <= 4000000;m++) {
        ll a = (2*b*m*n-b*m*m) / (n*n);
        if(a >= 0 && ((2*b*m*n-b*m*m) % (n*n)) == 0) kq++;
    }
    cout << kq-1;
    return 0;
}