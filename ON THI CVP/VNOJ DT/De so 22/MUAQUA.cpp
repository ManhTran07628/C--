#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "MUAQUA"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll i = 1,j = 1,min1 = 1e9;
    while(j <= n) {
        if(j-i+1 == m) {
            min1 = min(min1,abs(a[j]-a[i]));
            i++;
        }
        j++;
    }
    cout << min1;
    return 0;
}