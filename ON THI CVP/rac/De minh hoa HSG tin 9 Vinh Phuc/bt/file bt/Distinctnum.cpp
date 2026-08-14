#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N],b[N];
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
    ll n,m,k;
    cin >> n >> m >> k;
    ll max1 = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
        max1 = max(max1,b[i]);
    }
    if(k > max1) {
        cout << m;
        return 0;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ll i = 1,j = 1,dem = 0;
    while(i <= n && j <= m) {
        ll min1 = abs(a[i] - k);
        ll max1 = abs(a[i] + k);
        if(b[j] < min1) {
            j++;
        }
        else if(b[j] > max1) {
            i++;
        }
        else  {
            dem++;
            i++;
            j++;
        } 
    }
    cout << dem;
    return 0;
}