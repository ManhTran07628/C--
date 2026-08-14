#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll b[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TBC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    a[1] = b[1];
    ll sum = b[1];
    for(int i = 2;i <= n;i++) {
        sum += b[i];
        a[i] = (b[i]*i)-sum;
    }
    for(int i = 1;i <= n;i++) {
        cout << a[i] << " ";
    }
    return 0;
}