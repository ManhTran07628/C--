#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

ll cntn(ll k)
{
    ll cnt = 0;
    while(k > 0) {
        cnt++;
        k/=10;
    }
    return cnt;
}

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
    ll kt = 1;
    for(ll i = 1;i <= 100;i++) {
        if(cntn(i*i) != kt) {
            cout << '\n';
            kt++;
        }
        cout << cntn(i*i) << " ";
    }
    return 0;
}