#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SIBICE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,w,h;
    cin >> n >> w >> h;
    ll dcheo = sqrt(w*w+h*h);
    while(n--) {
        ll a1;
        cin >> a1;
        if(a1 <= dcheo) cout << "DA" << '\n';
        else cout << "NE" << '\n';
    }
    return 0;
}