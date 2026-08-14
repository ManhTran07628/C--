#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],f[N];

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
        f[a[i]]++;
    }
    int ans = 1;
    for(int i = 1;i<= N;i++) {
        if(f[i] >= 2) ans = max(ans,i);
        for(int j = i*2;j <= N;j+=i) {
            if(f[j] && f[i]) ans = max(ans,i);
        }
    }
    cout << ans;
    return 0;
}