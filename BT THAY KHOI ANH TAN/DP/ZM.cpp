#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int mp[MAXN],query[MAXN],dp[MAXN];
int a = 1,b = 1e9;
vector<int> cntpow;
void min_prime()
{
    for(int i = 2;i*i < MAXN;i++)
        if(mp[i] == 0)
           for(int j = i;j < MAXN;j+=i)
            if(mp[j] == 0) 
               mp[j] = i;

    for(int i = 2;i < MAXN;i++) 
        if(mp[i] == 0) mp[i] = i;
}

void backtracking(int id,int d,int k)
{
    int at = d;
    int bt = k/d;
    if(abs(a-b) > abs(at-bt)) {
        a = at;
        b = bt;
    }
    for(int i = id;i < cntpow.size();i++) {
        backtracking(i+1,d*cntpow[i],k);
    }
}
            
void process(int k,int i) {
    int k1 = k;
    while(k1 > 1) {
        cntpow.push_back(mp[k1]);
        k1 /= mp[k1];
    }
    backtracking(0,1,k);
    query[i] = max(a,b);
    cntpow.clear();
    a = 1;b = 1e9;
}

void solve()
{
    min_prime();
    for(int i = 2;i <= 1e6-7;i++) {
        process(i,i);
    }
    for(int i = 1;i <= 1e6-7;i++) {
        if(query[i] == i) dp[i] = dp[i-1]+1;
        else dp[i] = min(dp[i-1],dp[query[i]])+1;
    }
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n'; 
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}