#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll f[N];
void lich()
{
    for(int i = 1;i < N;i++) {
        f[i] = f[i-1] + i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CALENDAR"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    // ll a = 1,b = 32;
    // for(int i = a;i <= b;i++) {
    //     ll j = i;
    //     string k;
    //     while(j > 0) {
    //         k+= (j%2+'0');
    //         j /= 2;
    //     }
    //     reverse(k.begin(),k.end());
    //     cout << k << " " << i << '\n';
    // }
    lich();
    ll a,b;
    cin >> a >> b;
    ll a1 = floor(sqrt(a));
    ll b1 = round(sqrt(b));
    cout << f[b1] - f[a1];
    return 0;
}