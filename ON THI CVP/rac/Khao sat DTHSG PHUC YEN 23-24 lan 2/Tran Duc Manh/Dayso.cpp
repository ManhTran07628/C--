#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Dayso"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    int cnt = 0,max1 = a[k];
    for(int i = 1;i <= n;i++) {
        if(b[i] == max1) {
            cnt = i;
            break;
        }
    }
    cout << max1 << " " << cnt;
    return 0;
}