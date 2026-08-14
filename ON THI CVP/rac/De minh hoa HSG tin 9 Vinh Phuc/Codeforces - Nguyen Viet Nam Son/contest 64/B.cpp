#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],lt[N];
int M = 1e6;
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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        lt[a[i]]++;
    }
    int ans = 1;
    for(int i = 1;i <= 15;i++) {
        int sum = 0;
        for(int j = i;j <= 8888;j+=i) {
            sum += lt[a[j]];
        }
        cout << i << ' ' << sum << '\n';
        if(sum >= 2) ans = max(ans,i);
    }
    cout << ans;
    return 0;
}