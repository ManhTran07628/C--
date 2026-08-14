#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 5e6+7;
ll a[10001][10001],r[N],c[N];
ll m,n,k;

void sub4()
{
    while(k--) {
        char x;
        int f;
        cin >> x >> f;
        if(x == 'R') r[f]++;
        else c[f]++;
    }
    ll cnt = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if((c[j]+r[i]) % 2 == 1) cnt++;
        }
    }
    cout << cnt;
}

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
    cin >> m >> n >> k;
    sub4();
    return 0;
}