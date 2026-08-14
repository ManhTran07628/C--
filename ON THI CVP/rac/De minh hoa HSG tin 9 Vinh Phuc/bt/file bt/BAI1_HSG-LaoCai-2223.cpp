#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SODEP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll dem = 0;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            dem++;
            if(n / i != i) dem++;
        }
    }
    cout << dem;
    return 0;
}