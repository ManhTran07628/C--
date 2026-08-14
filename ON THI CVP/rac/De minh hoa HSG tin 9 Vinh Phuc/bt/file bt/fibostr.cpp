#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
string a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "fibostr"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    string x,y;
    cin >> x >> y;
    ll n;
    cin >> n;
    a[1] = x;
    a[2] = y;
    for(int i = 3;i <= n;i++) {
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n];
    return 0;
}