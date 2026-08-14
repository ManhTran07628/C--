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
    for(int i = 2;i <= N;i++) a[i] = 1;
    a[1] = a[0] = 0;
    for(int i = 2;i <= sqrt(N);i++) 
        if(a[i])
            for(ll j = i*i;j <= N;j+=i)
                a[j] = 0;
    ll a1,b;
    cin >> a1 >> b;
    for(int i = a1;i <= b;i++) {
        if(a[i] == 1) cout << i << '\n';
    }
    return 0;
}