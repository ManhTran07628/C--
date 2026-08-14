#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
ll tmp = 1e9+7;


ll ltnp(ll a,ll b)
{
    a = a % tmp;
    ll kq = 1;
    while(b > 0) {
        if(b % 2 == 1) kq = kq * a % tmp;
        b /= 2;
        a = a * a % tmp;
    }
    return kq;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BAI4"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,min1 = 1e5+5,kq = 1;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        for(int j = 2;j <= sqrt(a1);j++) {
            while(a1 % j == 0) {
                a[j]++;
                a1 /= j;
            }
        }
        if(a1 > 1) a[a1]++;
    }
    cin >> m;
    for(int i = 1;i <= m;i++) {
        ll a1;
        cin >> a1;
        for(int j = 2;j <= sqrt(a1);j++) {
            while(a1 % j == 0) {
                b[j]++;
                a1 /= j;
            }
        }
        if(a1 > 1) b[a1]++;
    }
    for(int i = 2;i <= min1;i++) {
        if (a[i] > 0 || b[i] > 0)
            kq *= ltnp(i,min(a[i],b[i])) % tmp;
    }
    cout << kq;
    return 0;
}
