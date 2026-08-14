#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MAXN = 2e6+7;
int n,a[MAXN],mp[MAXN];
int ans[MAXN],pre_pos[MAXN],suf_pos[MAXN];
void min_prime()
{
    for(int i = 2;i*i < MAXN;i++)
        if(mp[i] == 0)
            for(int j = i;j < MAXN;j+=i)
                if(mp[j] == 0) mp[j] = i;
    for(int i = 2;i < MAXN;i++) 
        if(mp[i] == 0) mp[i] = i;
}



void sol()
{
    min_prime();
    fill(ans+1,ans+n+1,oo);

    for(int i = 1;i <= n;i++) { // prefix
        int k = a[i],j = -1,dis = oo;
        while(k > 1) {
            int p = mp[k];
            if(pre_pos[p] != 0) {
                if(dis > i-pre_pos[p]) {
                    j = pre_pos[p];
                    dis = i-pre_pos[p];
                }
            }
            pre_pos[p] = i;
            while(k % p == 0) k /= p;
        }
        ans[i] = j;
    }

    for(int i = n;i >= 1;i--) { //suffix
        int k = a[i],j = -1,dis = oo;
        while(k > 1) {
            int p = mp[k];
            if(suf_pos[p] != 0) {
                if(dis > suf_pos[p]-i) {
                    j = suf_pos[p];
                    dis = suf_pos[p]-i;
                }
            }
            suf_pos[p] = i;
            while(k % p == 0) k /= p;
        }
        if(ans[i] == -1) ans[i] = j;
        else {
            if(abs(i-ans[i]) > abs(j-i)) ans[i] = j;
        }
    }
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sol();
    return 0;
}



// void sol()
// {
//     min_prime();
//     for(int i = 1;i <= n;i++) {
//         factorize(a[i],i);
//     }
//     for(int i = 1;i <= n;i++) {
//         int k = a[i];
//         int dis = LLONG_MAX,ok = LLONG_MAX;
//         while(k > 1) {
//             int p = mp[k];
//             if(ex[p].size() != 1) {
//                 int m = ex[p].size();
//                 int pos = lower_bound(ex[p].begin(),ex[p].end(),i) - ex[p].begin();
//                 if(pos > 0) {
//                     int j = ex[p][pos-1];
//                     int d = abs(i - j);
//                     if (dis > d) dis = d,ok = j;
//                     else if (dis == d) ok = min(ok,j);
//                 }
//                 if(pos + 1 < m) {
//                     int j = ex[p][pos+1];
//                     int d = abs(i - j);
//                     if(dis > d) dis = d,ok = j;
//                     else if(dis == d) ok = min(ok,j);
//                 }
//             }
//             while(k % p == 0) k /= p;
//         }
//         cout << (ok != LLONG_MAX ? ok : -1) << ' ';
//     }
// }