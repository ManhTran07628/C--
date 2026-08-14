#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BAI2"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,c;
    cin >> n >> c;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    ll dem = 0;
    for(int i = 1;i <= n-1;i++) {
        if(a[i+1] - a[i] > c) dem = 0;
        else dem++;
    }
    cout << dem+1;
    return 0;
}