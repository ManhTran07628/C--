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
    #define taskname "div7"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ll crr = 0;
        for(int j = i;j <= n;j++) {
            crr += a[j];
            if(crr % 7 == 0) ans = max(ans,j-i+1);
        }
    }
    cout << ans << '\n';
    return 0;
}