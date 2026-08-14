#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e7+7;
int M = 100;
int a,b,c,n,k;
int dem[200],s[MAXN];
int Fx(int x)
{
    return a*x+b;
}

signed main()
{
    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    cin >> a >> b >> c >> n >> k;
    s[1] = c;
    for(int i = 2;i <= n;i++) s[i] = (Fx(s[i-1])+M)%M;
    for(int i = 1;i <= n;i++) dem[s[i]]++;
    int cnt = 0;
    for(int i = 100;i >= 0;i--) {
        if(dem[i] >= k) {
            cout << i;
            return 0;
        }
        k -= dem[i];
    }

    return 0;
}