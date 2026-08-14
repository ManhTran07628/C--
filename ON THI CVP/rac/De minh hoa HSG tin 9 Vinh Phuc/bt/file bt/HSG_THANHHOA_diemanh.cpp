#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+5;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAU2"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) max1 = max(max1,b[a[i]]);
    cout << max1;
    return 0;
}