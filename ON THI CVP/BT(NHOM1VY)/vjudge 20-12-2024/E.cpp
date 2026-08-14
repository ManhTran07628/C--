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
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ll i = 1,j = 1,cnt = 0,max1 = 1;
    while(i <= n && j <= n) {
        if(a[i] <= b[j]) {
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        max1 = max(max1,cnt);
    }
    cout << max1;
    return 0;
}