#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+1;
ll a[N],b[N],c[N];

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
    for(int i = 1;i <= n-1;i++) 
        cin >> b[i];
    for(int i = 1;i <= n-2;i++) 
        cin >> c[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n);
    sort(c+1,c+n-1);
    for(int i = 1;i <= n;i++) {
        if(a[i] != b[i]) {
            cout << a[i] << '\n';
            break;
        }
    }
    for(int i = 1;i <= n;i++) {
        if(b[i] != c[i]) {
            cout << b[i] << '\n';
            break;
        }
    }
    return 0;
}