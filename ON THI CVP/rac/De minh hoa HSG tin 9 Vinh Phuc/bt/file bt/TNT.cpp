#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+1;
bool a[N];

ll tongchuso(ll k)
{
    ll kq = 0;
    while(k > 0) {
        ll tmp = k % 10;
        kq+=tmp;
        k/=10;
    }
    return kq;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tnt"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a1,b;
    cin >> a1 >> b;
    for(int i = 2;i <= 100;i++) a[i] = 1;
    for(int i = 2;i <= 100;i++) 
        if(a[i])
            for(int j = i*2;j <= 100;j+=i) 
                a[j] = 0;
    ll dem = 0;
    for(ll i = a1;i <= b;i++) {
        ll ans = tongchuso(i);
        if(a[ans] == 1) dem++;
    }
    cout << dem;
    return 0;
}