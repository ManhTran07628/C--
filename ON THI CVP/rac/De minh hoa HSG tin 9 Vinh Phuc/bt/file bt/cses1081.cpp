#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CDIV"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll kq = -1e9,max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        for(ll j = 1;j <= sqrt(a[i]);j++) {
            if(a[i] % j == 0) {
                b[j]++;
                max1 = max(max1,j);
                if(a[i] / j != j) {
                    ll tmp = a[i]/j;
                    b[tmp]++;
                    max1 = max(max1,tmp);
                }
            }
        }
    }
    for(ll i = 1;i <= max1;i++) {
        if(b[i] >= 2) kq = max(kq,i);
    }
    cout << kq;
    return 0;
}