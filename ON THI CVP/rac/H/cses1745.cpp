#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+1;
int a[N],f[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n;
    cin >> n;
    int m = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        m += a[i];
    }
    f[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= a[i];j--) {
            if(f[j-a[i]]) f[j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1;i <= m;i++) {
        if(f[i]) cnt++;
    }
    cout << cnt << '\n';
    for(int i = 1;i <= m;i++) {
        if(f[i]) cout << i << ' ';
    }
    return 0;
}