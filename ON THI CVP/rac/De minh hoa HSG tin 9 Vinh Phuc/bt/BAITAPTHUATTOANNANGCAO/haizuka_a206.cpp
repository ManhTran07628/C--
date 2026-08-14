#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

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
    ll a,b;
    cin >> a >> b;
    ll kq = 1;
    ll tmp = 1e9 + 7;
    a = a % tmp;
    while(b > 0) {
        if(b % 2 == 1) kq = kq * a % tmp;
        a = a * a % tmp;
        b /= 2;
    }
    cout << kq;
    return 0;
}