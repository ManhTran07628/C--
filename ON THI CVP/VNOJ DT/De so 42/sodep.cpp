#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "sodep"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll cnt = 0;
    for(int i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            cnt++;
            if(n / i != i) cnt++;
        }
    }
    cout << cnt;
    return 0;
}