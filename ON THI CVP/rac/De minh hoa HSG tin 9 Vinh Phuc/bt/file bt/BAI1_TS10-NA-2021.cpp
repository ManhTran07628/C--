#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
const int n1 = 1e5+1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TONGBP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    while(n--) {
        ll a1;
        cin >> a1;
        cout << a1*(a1+1)*(2*a1+1)/6 << '\n';
    }
    return 0;
}