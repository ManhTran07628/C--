#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "UOCNT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll dem = 0;
    for(int i = 2;i <= sqrt(n);i++) {
        bool kt = 0;
        while(n % i == 0) {
            n /= i;
            kt = 1;
        }
        if(kt) dem++;
    }
    if(n > 1) dem++;
    cout << dem;
    return 0;
}
