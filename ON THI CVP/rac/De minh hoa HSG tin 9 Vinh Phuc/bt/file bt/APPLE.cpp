#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

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
    ll d1 = 0,d2 = 0;
    for(int i =1;i <= n;i++) {
        cin >> a[i];
        if(a[i] % 3 ==1) d1++;
        if(a[i]%3 == 2) d2++;
    }
    d1 = d1 % 3;
    d2 = d2 % 3;
    cout << n - abs(d1-d2);
    return 0;
}
