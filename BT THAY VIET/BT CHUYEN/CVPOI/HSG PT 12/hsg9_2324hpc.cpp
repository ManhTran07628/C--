#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6 + 7;
const int lim = 1e7 + 7;
int n,k,a[MM],mp[lim],D[MM];

void sieve()
{
    for(ll i = 2;i * i < lim;i++)
        if(mp[i] == 0)
            for(int j = i;j < lim;j+=i)
                if(mp[j] == 0)
                    mp[j] = i;

    for(int i = 2;i < lim;i++) 
        if(mp[i] == 0)
            mp[i] = i;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin >> n >> k;
    int maxdiv = 1;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ll cntdiv = 1;
        while(a[i] > 1) {
            int p = mp[ a[i] ];
            int cnt = 0;
            while(a[i] % p == 0) {
                cnt++;
                a[i] /= p;
            }
            cntdiv *= (cnt + 1);
        }
        a[i] = cntdiv;
        maxdiv = max(maxdiv,a[i]);
    }

    for(int i = 1;i <= n;i++) {
        if(a[i] == maxdiv)  
            D[i] = 1;
    }

    int maxseg = oo,cntmax = 0;
    for(int i = 1,j = 1;i <= n;i++) {

        while(cntmax < k && j <= n) {
            cntmax += D[j];
            j++;
        }

        if(cntmax == k) maxseg = min(maxseg,j - i);
        cntmax -= D[i];
    }
    cout << (maxseg != oo ? maxseg : -1); 

    return 0;
}