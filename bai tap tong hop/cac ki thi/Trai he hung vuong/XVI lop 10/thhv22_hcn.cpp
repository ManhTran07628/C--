#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 300 + 7;
const int MS = 1e6 + 7;
int num_row,num_col,a[MM][MM];
int prime[MS];

void sieve()
{
    for(int i = 2;i < MS;i++) prime[i] = 1;
    for(ll i = 2;i * i < MS;i++)
        if(prime[i])
            for(ll j = i * i;j < MS;j += i)
                prime[j] = 0;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    cin >> num_row >> num_col;
    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) {
            cin >> a[i][j];
            a[i][j] = prime[ a[i][j] ];
        }

    ll res = 0;
    for(int i = 1;i <= num_row;i++) {
        for(int j = i + 1;j <= num_row;j++) {
            int cnt[3] = {};
            for(int k = 1;k <= num_col;k++) {
                if(a[i][k] & a[j][k]) {
                    res += cnt[1] + cnt[2];
                    cnt[2]++;
                }
                else if(a[i][k] ^ a[j][k] == 1) {
                    res += cnt[2];
                    cnt[1]++;
                }
            }
        }
    }
    cout << res;
        
    return 0;
}