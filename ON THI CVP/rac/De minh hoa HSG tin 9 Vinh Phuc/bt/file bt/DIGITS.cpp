#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
map<ll,ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DIGITS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 0;i <= n;i++) {
        ll j = i;
        while(j > 0) {
            a[(j % 10)]++;
            j /= 10;
        }
    }
    for(int i = 0;i <= 9;i++) {
        cout << i << " " << a[i] << '\n';
    }
    return 0;
}