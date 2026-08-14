#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "maxcross"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k,b;
    cin >> n >> k >> b;
    for(int i = 1;i <= b;i++) {
        cin >> a[i];
    }
    sort(a+1,a+b+1);
    a[0] = 0;a[n+1] = n+1;
    int i = 0,j = 1,cnt = 0,ans = b;
    while(i <= n && j <= n) {
        if(a[j] - a[i] < k) {
            j++;
            cnt++;
        }
        while(a[j] - a[i] >= k) {
            ans = min(ans,cnt);
            i++;
            cnt--;
        }
    }
    cout << ans;
    return 0;
}
// 1 2 5 9 10