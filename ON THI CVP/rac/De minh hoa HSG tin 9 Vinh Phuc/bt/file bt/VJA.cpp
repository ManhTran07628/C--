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
    ll n;
    cin >> n;
    ll dem = 0;
    while(n >= 100) {
        n -= 100;
        dem++;
    }
    while(n >= 20) {
        n -= 20;
        dem++;
    }
    while(n >= 10) {
        n -= 10;
        dem++;
    }
    while(n >= 5) {
        n -= 5;
        dem++;
    }
    while(n >= 1) {
        n -= 1;
        dem++;
    }
    cout << dem;
    return 0;
}