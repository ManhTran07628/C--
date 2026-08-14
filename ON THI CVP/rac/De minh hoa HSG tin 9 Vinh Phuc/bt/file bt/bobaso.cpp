#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BOBASO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll dem = 0;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n-2;i++) {
        ll p = i + 2;
        for(int j = i+1;j <= n-1;j++) {
            for(int k = p;k <= n;k++) {
                if(a[i]+a[j] == a[k]) dem++;
                else if(a[i]+a[j] < a[k]) break;
                p = k;
            }
        }
    }
    cout << dem;
    return 0;
}
