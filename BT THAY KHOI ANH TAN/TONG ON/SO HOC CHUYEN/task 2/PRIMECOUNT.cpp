#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 2e6+7;
int prime[MM];
void segment_sieve(int L,int R)
{
    for(int i = L;i <= R;i++) prime[i-L] = 1;

    for(int i = 2;i*i <= R;i++) {
        int d = (L+i-1)/i*i;
        for(int j = max(i*i,d);j <= R;j += i)
            prime[j-L] = 0;
    }
    if(L == 1) prime[0] = 0;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l,r;
        cin >> l >> r;
        segment_sieve(l,r);
        int cnt = 0;
        for(int i = l;i <= r;i++) {
            if(prime[i-l]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}