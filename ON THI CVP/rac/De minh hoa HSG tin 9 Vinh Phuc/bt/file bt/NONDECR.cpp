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
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    ll max1 = -1e9,dem = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i] >= a[i-1]) dem++;
        else dem = 1;
        max1 = max(max1,dem);
    }
    cout << max1;
    return 0;
}