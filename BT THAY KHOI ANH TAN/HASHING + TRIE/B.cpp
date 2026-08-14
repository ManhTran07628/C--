#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 5e4+7;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
const int base = 256;
const int ms = 1;
int n,k;
string A;
ll hashA[ms + 5][MM + 5],Pow[ms + 5][MM + 5];

ll getHash(int l,int r,int k)
{
    return (hashA[k][r] - hashA[k][l-1] * Pow[k][r-l+1] % MOD[k] + MOD[k]) % MOD[k];
}

bool check(int sz)
{
    vector<ll> valid[ms + 5];

    for(int j = 0;j < ms;j++)   
        valid[j].push_back(-1);

    for(int i = 1;i <= n-sz+1;i++) {

        for(int j = 0;j < ms;j++) 

            valid[j].push_back(getHash(i,i+sz-1,j));

        

    }

    for(int j = 0;j < ms;j++)
        sort(valid[j].begin(),valid[j].end());

    int cnt = 1;
    for(int i = 1;i <= n-sz+1;i++) {
        bool ok = 1;
        for(int j = 0;j < ms;j++) {
            if(valid[j][i] != valid[j][i-1]) ok = 0;
        }

        if(ok) cnt++;
        else cnt = 1;

        if(cnt >= k) return 1;
    }
    return 0;

}

void solve()
{
    cin >> n >> k >> A;
    A = ' ' + A;
    for(int j = 0;j < ms;j++) {

        Pow[j][0] = 1;
        for(int i = 1;i <= n;i++)
            Pow[j][i] = (Pow[j][i-1] * base) % MOD[j];

    }

    for(int j = 0;j < ms;j++) 
        for(int i = 1;i <= n;i++)
            hashA[j][i] = (hashA[j][i-1] * base + A[i] - '0' + 1) % MOD[j];

    int l = 0,r = n,ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;

    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}