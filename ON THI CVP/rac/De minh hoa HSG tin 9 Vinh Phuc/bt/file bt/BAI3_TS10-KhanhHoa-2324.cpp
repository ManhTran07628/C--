#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PRIZE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    if(m > n) {
        for(int i = 1;i <= m;i++) {
            cin >> a[i];
        }
        sort(a+1,a+m+1);
        ll min1 = a[1],kqmax = -1e9,j = 1;
        for(int i = n;i <= m;i++,j++) {
            min1 = a[j];
            kqmax = max(kqmax,min1*n);
        }
        ll k = 1;
        for(int i = j+1;i <= m;i++,k++) {
            min1 = a[i];
            kqmax = max(kqmax,min1*k);
        }
        cout << kqmax;
    }
    else {
        for(int i = 1;i <= m;i++) {
            cin >> a[i];
        }
        sort(a+1,a+m+1);
        ll kqmax = -1e9,min1 = 0;
        ll j = 1;
        for(int i = m;i >= 1;i--,j++) {
            min1 = a[i];
            kqmax = max(kqmax,min1*j);
        }
        cout << kqmax;
    }
    return 0;
}
