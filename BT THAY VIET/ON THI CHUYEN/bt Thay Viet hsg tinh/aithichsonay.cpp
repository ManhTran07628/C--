#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
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
    ll x;
    cin >> x;
    ll ct = 0;
    if(x % 2 == 0) ct++;
    if(x > 4 && x <= 12) ct++;
    
    if(ct == 2) cout << 1 << " ";
    else cout << 0 << " ";

    if(ct == 1 || ct == 2) cout << 1 << " ";
    else cout << 0 << " ";

    if(ct == 1) cout << 1 << " ";
    else cout << 0 << " ";

    if(ct == 0) cout << 1;
    else cout << 0;

    return 0;
}